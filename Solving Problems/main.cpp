#include <iostream>
#include "Problems.h"

int lol();

void main() {
	//Problem1::test_twoSum();
    problem2::test_cases();
	//problem2

    //lol();
}



struct Student {
    std::string name;
    int grade;
};

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << student.name << " - " << student.grade;
    return os;
}

int lol() {
    std::vector<Student> students = {
        {"Alice", 90},
        {"Bob", 85},
        {"Charlie", 80},
        {"David", 75},
        {"Eve", 70}
    };

    std::cout << "\xC9"; // top left corner
    for (int i = 0; i < 10; i++) {
        std::cout << "\xCD"; // horizontal line
    }
    std::cout << "\xBB\n"; // top right corner

    for (const auto& student : students) {
        std::cout << "\xBA " << student << " \xBA\n"; // vertical line
    }

    std::cout << "\xC8"; // bottom left corner
    for (int i = 0; i < 10; i++) {
        std::cout << "\xCD"; // horizontal line
    }
    std::cout << "\xBC\n"; // bottom right corner

    return 0;
}