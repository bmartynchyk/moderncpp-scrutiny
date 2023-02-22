#include "overloaded-functions.h"

using namespace std;


int Sum(int a, int b, int c) {
	cout << "Thread id: " << this_thread::get_id() << "; Task: Sum(a, b, c);" << endl;
	return a + b + c;
}

int Sum(int a, int b) {
	cout << "Thread id: " << this_thread::get_id() << "; Task: Sum(a, b);" << endl;
	return a + b;
}

int Sum(int a) {
	cout << "Thread id: " << this_thread::get_id() << "; Task: Sum(a);" << endl;
	return a;
}


void overloaded_functions_test() {
	int result = 0;
	auto thrd = make_unique<thread>([&result]() {result = Sum(11, 12, 13); });
	
	thrd->join();
	cout << "Returned result: " << result << endl;

	thrd = make_unique<thread>([&result]() {result = Sum(11, 12); });
	thrd->join();
	cout << "Returned result: " << result << endl;

	thrd = make_unique<thread>([&result]() {result = Sum(11); });
	thrd->join();
	cout << "Returned result: " << result << endl;
}