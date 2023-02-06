#pragma once

#include <mutex>


////////////////////////////////////////////////////////////////////////////////////////////////////
// Singleton_v1 ensures that only one instance of this class will exist for the duration of the program.
class Singleton_v1 {
public:
    inline static Singleton_v1& getInstance() {
        static std::mutex m;
        std::unique_lock<std::mutex> lock(m); // For tread-safe using.

        static Singleton_v1 instance;
        return instance;
    }

private:
    Singleton_v1() = default;
    ~Singleton_v1() = default;
    Singleton_v1(const Singleton_v1&) = delete;
    Singleton_v1& operator=(const Singleton_v1&) = delete;
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//  Singleton_v2 is a template version of pattern. This version ensures the same condition as the 
// previous one but for the particular type T.
template<typename T>
class Singleton_v2 {
public:
    inline static T& getInstance() {
        static std::mutex m;
        std::unique_lock<std::mutex> lock(m); // For tread-safe using.

        static T instance;
        return instance;
    }

private:
    Singleton_v2() = default;
    ~Singleton_v2() = default;
    Singleton_v2(const Singleton_v2&) = delete;
    Singleton_v2& operator=(const Singleton_v2&) = delete;
};


 void TestSingleton();