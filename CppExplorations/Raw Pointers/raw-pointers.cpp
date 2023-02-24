#include "raw-pointers.h"

using namespace std;

void raw_pointers_explore() {
	////////////////////////////////////////////////////////////////////////////////
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
		float* p1 = &a;

		cout << "&p1: [" << &p1 << "]; p1: [" << p1 
			<< "];\n&a1: [" << &a << "]; a1: [" << a  << "];\n";

		p1 = &b; // Changing the address pointed to by the pointer.

		cout << "\n&p1: [" << &p1 << "]; p1: [" << p1 << "]; *p1: [" << *p1 
			<< "];\n &b: [" << &b << "];  b: [" << b << "];\n";
	}


	////////////////////////////////////////////////////////////////////////////////
	// Case #3. Const context while call operator* ().
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
	}


}