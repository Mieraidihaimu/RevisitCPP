#include <gtest/gtest.h>
#include <gmock/gmock.h>

class MockDiskIO : public DiskIO {
public:
    MOCK_METHOD(void, write, (const std::string& key, const std::string& value), (override));
    MOCK_METHOD(std::optional<std::string>, read, (const std::string& key), (override));
};

TEST(LRUCacheTest, PutAndGet) {
    auto mockDiskIO = std::make_unique<MockDiskIO>();
    EXPECT_CALL(*mockDiskIO, write(testing::_, testing::_)).Times(1);
    EXPECT_CALL(*mockDiskIO, read(testing::_)).WillOnce(testing::Return("value2"));

    LRUCache<int, std::string> cache(1, std::move(mockDiskIO));
    cache.put(1, "value1");
    cache.put(2, "value2"); // this will remove key 1 and write it to disk
    ASSERT_EQ(*cache.get(1), "value2"); // this will read key 1 from disk
}
