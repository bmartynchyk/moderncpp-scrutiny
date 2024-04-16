#include <iostream>
#include <mutex>
#include "Problems.h"

#include <thread>


class protected_string {
public:

	void set(const std::string& str) const {
		lock_guard lock(m_mutex);
		m_string = str;
	}

	const std::string& get() const {
		lock_guard lock(m_mutex);
		return m_string;
	}

private:

	mutable std::string m_string;
	mutable std::mutex m_mutex;
};

void* ::operator new(std::size_t size) throw(std::bad_alloc) {
	void* p = std::malloc(size);

	cout << "\n!!Overloaded new!!\n";
	if (!p) throw std::bad_alloc();

	return p;
}

struct dd {
	dd() {
		int* ptr = new int[100];
		cout << "\ndd constructor\n";
	}

	void* operator new(std::size_t size) throw(std::bad_alloc) {
		cout << "\ndd operator new\n";

		//void* p = nullptr;
		void* p = std::malloc(size);

		//if (!p) {
		//	throw std::bad_alloc();
		//}
		return p;

	}
};

class Test {
public:
	Test() {
		std::cout << "Test::Test()" << std::endl;
	}

	void* operator new (std::size_t size) throw (std::bad_alloc) {
		std::cout << "Test::operator new(" << size << ")" << std::endl;
		return ::operator new(size);
	}
};


void main() {
	//int* k = new int;
	dd* kk = new dd();

	Test* t = new Test();
	void* p = Test::operator new(100); // 100 для различия в выводе
	
	void* t1 = Test::operator new(200);
	Test* ptr1 = new Test();


	cout << endl << sizeof(Test) << endl;



	//Problem1::test_twoSum();
    //problem2::test_cases();
}




