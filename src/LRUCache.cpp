#include <unordered_map>
#include <list>
#include <iostream>
#include <fstream>
#include <optional>
#include <memory>
#include <experimental/filesystem>

namespace fs = std::filesystem;

class DiskIO {
public:
    virtual ~DiskIO() = default;
    virtual void write(const std::string& key, const std::string& value) {
        std::ofstream outFile(key, std::ios::binary);
        outFile << value;
    }

    virtual std::optional<std::string> read(const std::string& key) {
        std::ifstream inFile(key, std::ios::binary);
        if (!inFile) {
            return {};
        }
        std::string val;
        inFile >> val;
        return val;
    }
};

template<typename Key, typename Value>
class LRUCache {
    std::unordered_map<Key, typename std::list<std::pair<Key, Value>>::iterator> cacheMap;
    std::list<std::pair<Key, Value>> lruList;
    size_t capacity;
    std::string filePath = "./cache/";
    std::unique_ptr<DiskIO> diskIO;

public:
    LRUCache(size_t capacity, std::unique_ptr<DiskIO> diskIO)
        : capacity(capacity), diskIO(std::move(diskIO)) {
        if (!fs::exists(filePath)) {
            fs::create_directory(filePath);
        }
    }

    std::optional<Value> get(Key key) {
        auto foundIter = cacheMap.find(key);
        if (foundIter == cacheMap.end()) {
            auto val = diskIO->read(filePath + std::to_string(key));
            if (!val.has_value()) {
                return {};
            }
            put(key, val.value());
            return val.value();
        }
        lruList.splice(lruList.begin(), lruList, foundIter->second);
        return foundIter->second->second;
    }

    void put(Key key, Value value) {
        auto foundIter = cacheMap.find(key);
        if (foundIter != cacheMap.end()) {
            lruList.splice(lruList.begin(), lruList, foundIter->second);
            foundIter->second->second = value;
            return;
        }
        if (cacheMap.size() == capacity) {
            diskIO->write(filePath + std::to_string(lruList.back().first), lruList.back().second);
            cacheMap.erase(lruList.back().first);
            lruList.pop_back();
        }
        lruList.emplace_front(key, value);
        cacheMap[key] = lruList.begin();
    }
};

int lruDisplay() {
    auto diskIO = std::make_unique<DiskIO>();
    LRUCache<int, std::string> cache(2, std::move(diskIO));
    cache.put(1, "value1");
    cache.put(2, "value2");
    std::cout << "Get(1): " << *cache.get(1) << "\n";
    cache.put(3, "value3"); // this will remove key 2 and write it to disk
    std::cout << "Get(2): " << *cache.get(2) << "\n"; // this will read key 2 from disk
    return 0;
}
