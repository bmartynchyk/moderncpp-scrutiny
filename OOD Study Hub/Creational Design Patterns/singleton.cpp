#include <unordered_map>
#include <iostream>
#include "singleton.h"

using namespace std;

struct SomeParams {
    int a = 10;
    float b = -12.54;
    unordered_map<string, string> hashtable;

    inline static void OutParamsState(const SomeParams& sp) {
        auto print_key_value = [](const auto& key, const auto& value) {
            cout << "Key: " << key << "; Value: " << value << ";\n";
        };  // Lambda function to print key-value pairs.

        cout << "global.a = " << sp.a << "; global.b = " << sp.b << "\n";

        for (const auto& [key, value] : sp.hashtable)
            print_key_value(key, value);

        cout << endl;
    }
};

void TestSingleton() {
    auto& global = Singleton_v2<SomeParams>::getInstance();

    global.hashtable.insert({ "Ball.fbx", "5Mb" });
    global.hashtable.insert({ "Project.uproj","2Kb" });
    global.hashtable.insert({ "Sound.mp4","603Kb" });

    SomeParams::OutParamsState(global); // Check 'global' state.

    global.a = 200;
    global.b = -34.5;
    global.hashtable.insert({ "backdrop.hdr","31Mb" });

    auto& global2 = Singleton_v2<SomeParams>::getInstance();

    SomeParams::OutParamsState(global2); // Check 'global2' state.

    global2.a = 1200;
    global2.b = 100;
    global2.hashtable.clear();

    SomeParams::OutParamsState(global); // Check 'global' state.
}