#include <iostream>

#include "constructor-calls-explore.h"


using namespace std;

// Implemented simple classes.
struct ABase {
    ABase() { cout << "ABase\n"; }
    ~ABase() { cout << "~ABase\n"; }
};

struct BBase {
    BBase() { cout << "BBase\n"; }
    ~BBase() { cout << "~BBase\n"; }
};

struct AField {
    AField() { cout << "AField\n"; }
    ~AField() { cout << "~AField\n"; }
};

struct BField {
    BField() { cout << "BField\n"; }
    ~BField() { cout << "~BField\n"; }
};


// Creation scheme of Current0 #0
// 
//  Inherited objects are created first, because they first located in memory scheme of object.
//  Here how memory scheme of object looks like:
// struct Current0 {
//      ABase::ABase(); // List of inherited objects. Who listed first - constructed first.
//      BBase::BBase(); 
//      BField(); // List of object's fields // Who listed first - constructed first.
//      AField();
//      this->Current0(); // Object itself
// }
// 
// ==> Stages of object construction:
// 1 - ABase::ABase();
// 2 - BBase::BBase();
// 3 - BField();
// 4 - AField();
// 5 - Current0();
struct Current0 : ABase, BBase {
    Current0() { cout << "Current0\n"; }
    ~Current0() { cout << "~Current0\n"; }
private:
    BField b;
    AField a;
};

// Creation scheme of Current1 #1
// 1 - BBase::BBase();
// 2 - ABase::ABase();
// 3 - AField();
// 4 - Current1();
struct Current1 : BBase, ABase {
    AField a;

    Current1() { cout << "Current1\n"; }
    ~Current1() { cout << "~Current1\n"; }
};

// Creation scheme of Current2 #2
// 1 - Current1::Current1(); - uses whole scheme #1 for creating Current1 object;
//      1.1 - BBase::BBase();
//      1.2 - ABase::ABase();
//      1.3 - AField();
//      1.4 - Current1::Current1(); - object Current1 itself;
// 2 - BField();
// 3 - Current2();
struct Current2 : Current1 {
    BField b;

    Current2() { cout << "Current2\n"; }
    ~Current2() { cout << "~Current2\n"; }
};


void constructor_calls_explore() {
    { // Test 1; Will be deleted when go out of this block.
        cout << "[current0]: \n";
        Current0 current0;
    }

    { // Test 2;
        cout << "\n[current1]: \n";
        Current1 current1;
    }

    { // Test 3;
        cout << "\n[current2]: \n";
        Current2 current2;
    }

    cout << "\n";
}