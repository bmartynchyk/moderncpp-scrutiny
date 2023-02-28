#include "raw-pointers.h"

using namespace std;


void f() { cout << "fuc f\n"; }


void raw_pointers_explore() {	////////////////////////////////////////////////////////////////////////////////
	// Case #1. Declaration of pointer.
	{
		int a; // Contains random value.
		float* p; // Contains random address.

		char* chptr1, chptr2;
		// chptr1 - pointer on char type.
		// chptr2 - char type - because* refers to a variable name, not a type.
	}

	////////////////////////////////////////////////////////////////////////////////
	// Case #2. Operation & and * with pointer.
	{
		float a = 465;
		float b = 20;
		float* p1 = &a; // State 1.

		cout << "State #1\n&p1: [" << &p1 << "]; p1: [" << p1 
			<< "];\n&a1: [" << &a << "]; a1: [" << a  << "];\n";

		p1 = &b; // State 2 - changing the address pointed to by the pointer.

		cout << "State #2\n&p1: [" << &p1 << "]; p1: [" << p1 << "]; *p1: [" << *p1 
			<< "];\n &b: [" << &b << "];  b: [" << b << "];\n";
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
		double const* p0 = &val1; // Constantness for type.
		const double* p1 = &val1; // Constantness for type.
		double* const p2 = &val2; // Constantness for pointer.
		double const* const p3 = &val2; // Constantness both for type and pointer.

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
		int const* const p2 = &c;               // Const pointer on const type.
		int const* const* pp2 = &p2;            // Pointer on const pointer on const type.
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