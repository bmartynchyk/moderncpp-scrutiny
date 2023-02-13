#include "mutex-basics.h"

#define SIDE 4

using namespace std;


mutex mtx;

void print_matrix(char ch) {
	// Some work before critical section.
	this_thread::sleep_for(chrono::milliseconds(1300));

	mtx.lock(); // Critical section. Only one thread has access.
	
	for (int i = 0; i < SIDE; i++) {
		this_thread::sleep_for(chrono::milliseconds(50));
		for (int j = 0; j < SIDE; j++)
			cout << ch;
		cout << endl;
	}

	cout << endl;

	mtx.unlock();

	// Some work after critical section.
	this_thread::sleep_for(chrono::milliseconds(500));
}


void mutex_basics_test() {
	vector<shared_ptr<thread>> threads {
		make_shared<thread>(print_matrix, 'o'),
		make_shared<thread>(print_matrix, 'x'),
		make_shared<thread>(print_matrix, '*')
	};

	vector <unique_ptr<thread>> threads2;
	threads2.push_back(make_unique<thread>(print_matrix, '#'));
	threads2.push_back(make_unique<thread>(print_matrix, '~'));

	for (const auto &thrd : threads)
		thrd->join();

	threads2[0]->join();
	threads2[1]->join();

}