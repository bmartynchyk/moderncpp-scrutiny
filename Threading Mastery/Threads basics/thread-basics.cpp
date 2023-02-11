#include "threads-basic.h"

using namespace std;

void SomeWork(int num, int delay) {
	//cout << "Thread id: " << this_thread::get_id() << "; Task: SomeWork();" << endl;

	for (int i = 0; i < num; i++) {
		this_thread::sleep_for(chrono::milliseconds(delay));
		cout << "Thread id: " << this_thread::get_id() << "; SomeWork(...): " << i << endl;
	}
}


void threads_basics_test() {
	thread* ptr = nullptr;
	thread th1(SomeWork, 7, 1000); // (1) A new thread will be created and SomeWork will be performing in separate thread.

	// (2) If we make detach we will broke the connection between 'main' thread and 'th'.
	// th.detach(); 

	thread th2(SomeWork, 4, 2000);

	


	for (int i = 0; i < 10; i++) {
		// (3) Stop current thread for some time.
		this_thread::sleep_for(chrono::milliseconds(1500));

		// (4) Get identifier of thread.
		cout << "Thread id: " << this_thread::get_id() << "; Task: main();" << endl;
	}
	//SomeWork();

	th1.join();
	th2.join();
}