#include "raw-pointers.h"

using namespace std;


void f() { cout << "fuc f\n"; }

int* funcAddr(int arr[]) {
	int* ptr = arr + 2;

	int arr2[121];
	int arr1[123];
	int arr3[]{ 1 };
	void (*ptr_f)() = nullptr;

	cout << typeid(arr).name() << endl;
	cout << typeid(arr1).name() << endl;
	cout << typeid(arr2).name() << endl;
	cout << typeid(arr3).name() << endl;
	cout << typeid(f).name() << endl;
	cout << typeid(ptr_f).name() << endl;

	cout << "\ninside the func:\n&ptr: " << &ptr << "; ptr: " << ptr << "; *ptr: " << *ptr;

	return ptr;
}

void raw_pointers_explore() {
	////////////////////////////////////////////////////////////////////////////////
	// Case #1. Declaration of raw pointer.
	{
		int a; // Contains random value.
		float* p; // Contains random address.

		char* chptr1, chptr2;
		// chptr1 - pointer on char type.
		// chptr2 - char type - because* refers to a variable name, not a type.

		double val1 = 200;
		double* p1 = &val1;
		double** p2 = &p1; // Pointer on pointer.
	}

	////////////////////////////////////////////////////////////////////////////////
	// Case #2. &,* operation with raw pointer.
	{
		float b = 20;
		float a = 465;
		float* p = &a;

		cout << "&a = " << &a << endl;
		cout << "&p: [" << &p << "]; p: [" << p << "];\n";


		//float a = 465;
		//float* p = &a;
		cout << "*p = " << *p << endl;



		// Changing state on runtime.
		float* p1 = &a; // State 1.

		cout << "State #1\n&p1: [" << &p1 << "]; p1: [" << p1 
			<< "];\n&a1: [" << &a << "]; a1: [" << a  << "];\n";

		p1 = &b; // State 2 - changing the address pointed to by the pointer.

		cout << "State #2\n&p1: [" << &p1 << "]; p1: [" << p1 << "]; *p1: [" << *p1 
			<< "];\n &b: [" << &b << "];  b: [" << b << "];\n";
	}

	////////////////////////////////////////////////////////////////////////////////
	// Case #3. Raw pointers on array.
	{
		int a = 10;
		const int* pa = &a;
		
		const int b = 20;
		int const* pb = &b;

		//const int c = 30;
		//int* pc = &c; // Error

		int d = 40;
		int* const pd = &d;

	}

	////////////////////////////////////////////////////////////////////////////////
	// Case #3. Raw pointers on array.
	{
		int a1[4];
		int const a2[3] = { 1, 2, 3 }; // Should be initialized at once.
		
		// int* p0 = a2; - Error
		int const* p1 = a2;

		p1 = a1;





		int arr[12];

		int* const ptr = arr;

		for (int i = 0; i < 12; i++) {
			cout << arr[i] << endl;
		}
	}

	// void
	{
		int g = 13;
		void* ptr = &g;

		// double* p1 = static_cast<double*>(&g); - invalid type conversion
		double* p2 = static_cast<double*>(ptr);
		int* p3 = static_cast<int*>(ptr);

		cout << "(double) *p2 =  " << *p2 << endl;
		cout << "(int) *p3: " << *p3 << endl;


	}

	{
		int arr[5] = { 1, 2, 3, 4, 5 };

		int* ptr = funcAddr(arr);

		cout << "\noutside the func:\n&ptr: " << &ptr << "; ptr: " << ptr << "; *ptr: " << *ptr << endl;
	}

	////////////////////////////////////////////////////////////////////////////////
	// Case #3. Constant context while call operator* ().
	{
		struct Rectangle {
			int a;
			mutable int b;

			void setA(int a) { this->a = a; }
			void setB(int b) const { this->b = b; }
		};

		Rectangle rect1;
		const Rectangle rect2;
		const Rectangle* ptr = &rect2;

		rect1.setA(1);
		// rect2.setA(2); // Error
		rect2.setB(3);

		// ptr->setA(4); // Error
		ptr->setB(4);

		ptr = &rect1;
		// ptr->setA(5); // Error
		ptr->setB(6);

		const Rectangle* ptr1 = &rect1; // Added constant behavior by pointer.  ó

		rect1.setA(7);
		rect2.setB(8);
		//ptr1->setA(9); // Error
		ptr1->setB(10);
	}

	////////////////////////////////////////////////////////////////////////////////
	// Case #4. Using const for type and for pointer itself.
	{
		double val1 = 20;
		double val2 = 30;

		// Constantness for type.
		double const* p0 = &val1; 
		const double* p1 = &val1;

		// Constantness for pointer.
		double* const p2 = &val2;

		// Constantness both for type and pointer.
		double const* const p3 = &val2; 

		// *p1 = 500; // Error - broken constant behavior. Impossible to modify.
		cout << "\n\n&p1:   [" << &p1 << "]; p1:   [" << p1 << "]; *p1:  [" << *p1 
			<< "];\n&val1: [" << &val1 << "]; val1: [" << val1 << "];\n\n";

		p1 = &val2; // Ok
		cout << "&p1:   [" << &p1 << "]; p1:   [" << p1 << "]; *p1:  [" << *p1
			<< "];\n&val1: [" << &val1 << "]; val1: [" << val1 << "];\n"
			<< "&val2: [" << &val2 << "]; val2: [" << val2 << "];\n";

		*p2 = 500; //Ok
		cout << "\n\n&p2:   [" << &p2 << "]; p2:   [" << p2 << "]; *p2:  [" << *p2
			<< "];\n&val2: [" << &val2 << "]; val2: [" << val2 << "];\n\n";

		// p2 = &val1;
	}

	////////////////////////////////////////////////////////////////////////////////
	// Case #5. Non-constant behavior for constant object.
	{
		const int a = 30;
		int b;
		const int* p1 = &a;
		const int* p2 = &b; // Declared constant behavior for non-constant type

		// *p1 = 123; - Error
		// *p2 = 123;
		
		//int* const p3 = &a; // Error - because declared non-constant behavior for constant object.
		int* const p4 = &b;
		// int* p5 = &a; // Error
		int* p6 = &b;
	}

	////////////////////////////////////////////////////////////////////////////////
	// Case #6. Pointer to other pointer.
	{
		int a = 40;
		int* p = &a;
		int** pp = &p;

		int b = 50;
		int const* p1 = &b;
		int const** pp1 = &p1;
		const int c = 30;
		int const* const p2 = &c; // Const pointer on const type.
		int const* const* pp2 = &p2; // Pointer on const pointer on const type.
		int const* const* const pp3 = &p2; // Const pointer on const pointer on const type.
	}

	////////////////////////////////////////////////////////////////////////////////
	// Case #7. Raw-pointer with arrays.
	{
		int arr[5] = { 1,2,3,4,5 };
		int* p = arr; // Name of array is a pointer to this array.

		cout << "p = " << p;
		cout << "\narr = " << arr; // = &arr
		cout << "\n&arr = " << &arr; // = arr
		cout << "\n&arr[0] = " << &arr[0]; // Address of first element.
		
		for (int i = 0; i < 5; i++)
			cout << "\np[" << i << "] = " << p[i] << "; arr[" << i << "] = " << arr[i];
	}

	////////////////////////////////////////////////////////////////////////////////
	// Case #7. Raw-pointer with arrays.
	{
		auto p = f;
		p();
	}

}