#include <iostream>
#include <thread>

using namespace std;

void basicThreads() {
    // create a thread
    auto func = []() {
        cout << "Hello World" << endl;
    };

    thread t1(func);
    t1.join();

    // create a thread with arguments
    auto func2 = [](int x) {
        cout << "Hello World: " << x << endl;
    };

    thread t2(func2, 10);
    t2.join();

    // create a thread with arguments and return value
    auto func3 = [](int x) {
        cout << "Hello World: " << x << endl;
        return x;
    };

    thread t3(func3, 10);
    t3.join();
    cout << "Thread return value: " << t3.joinable() << endl;

    // implement a read write lock
    int sharedVariable = 0;
    mutex m1;
    auto readFunc = [&]() {
        m1.lock();
        cout << "Read: " << sharedVariable << endl;
        cout << "Thread ID: " << this_thread::get_id() << endl;
        m1.unlock();
    };

    auto writeFunc = [&]() {
        m1.lock();
        sharedVariable++;
        cout << "Write: " << sharedVariable << endl;
        cout << "Thread ID: " << this_thread::get_id() << endl;
        m1.unlock();
    };

    thread t4(readFunc);
    thread t5(writeFunc);
    t4.join();
    t5.join();

    // implement a read write lock with lock_guard
    int sharedVariable2 = 0;
    mutex m2;
    auto readFunc2 = [&]() {
        lock_guard<mutex> guard(m2);
        cout << "Read: " << sharedVariable2 << endl;
        cout << "Thread ID: " << this_thread::get_id() << endl;
    };

    auto writeFunc2 = [&]() {
        lock_guard<mutex> guard(m2);
        sharedVariable2++;
        cout << "Write: " << sharedVariable2 << endl;
        cout << "Thread ID: " << this_thread::get_id() << endl;
    };

    thread t6(readFunc2);
    thread t7(writeFunc2);
    t6.join();
    t7.join();

    // multiple threads
    auto func4 = [](int x) {
        cout << "Hello World: " << x << endl;
        cout << "Thread ID: " << this_thread::get_id() << endl;
    };

    thread t8(func4, 10);
    thread t9(func4, 20);
    t8.join();
    t9.join();

    // manage multiple threads and its memory
    auto func5 = [](int x) {
        cout << "Hello World: " << x << endl;
        cout << "Thread ID: " << this_thread::get_id() << endl;
    };

    thread t10(func5, 10);
    thread t11(func5, 20);
    t10.detach();
    t11.detach();

    // manage multiple threads and its memory with join
    auto func6 = [](int x) {
        cout << "Hello World: " << x << endl;
        cout << "Thread ID: " << this_thread::get_id() << endl;
    };

    thread t12(func6, 10);
    thread t13(func6, 20);
    t12.join();
    t13.join();

}