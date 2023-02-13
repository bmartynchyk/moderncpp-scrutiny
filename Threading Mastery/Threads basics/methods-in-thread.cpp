#include "methods-in-thread.h"


using namespace std;


class Grid {
public:
	void printer() {
		cout << "Thread id: " << this_thread::get_id() << "; Task: printer();" << endl;
	}

	int suma(int a, int b) {
		cout << "Thread id: " << this_thread::get_id() << "; Task: suma(a, b);" << endl
			<< "Result: " << a + b << endl;
		return a + b;
	}
};


void methods_in_threads_test() {
	int res = 0;
	Grid grd;

	// Case #1
	auto thr0 = make_shared<thread>(&Grid::printer, grd);
	thr0->join();

	// Case #2
	thr0 = make_shared<thread>([&]() {grd.printer(); });
	thr0->join();

	// Case #3
	thr0 = make_shared<thread>([&]() {res = grd.suma(200, 300); });
	thr0->join();

	// Case #4
	thr0 = make_shared<thread>(&Grid::suma, grd, 300, 400);
	thr0->join();
}