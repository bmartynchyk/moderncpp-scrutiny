#include "casts-explore.h"


using namespace std;


void static_cast_operator() {
	double a_double = 53.34;

	// Implicit conversion
	int a_int = a_double;  // in C/C++

	// Explicit conversion
	a_int = (int)a_double; // Old C-style
	a_int = int(a_double); // Old C++-Style
	a_int = static_cast<int>(a_double); // Modern C++-Style
	

	////////////////////////////////////////////////////////////////////////////////
	// Case #1. Simple how to use.
	double expr = 5.55 + 4.44;
	int num1 = static_cast<int>(expr);
	int num2 = static_cast<int>(5.55 + 4.44);

	cout << "Case #1\nexpr: " << expr
		<< "\nnum1: " << num1 << "\nnum2: " << num2 << endl;


	////////////////////////////////////////////////////////////////////////////////
	// Case #2. How to use with pointers and some pitfalls.
	int* ptr_int = new int (10);
	double* ptr_double = (double*)ptr_int;

	cout << "\nCase #2\nptr_int: " << *ptr_int 
		<< "\nptr_double: " << *ptr_double << endl;

	int* ptr_int1 = new int(10);
	//double* ptr_double1 = static_cast<double*>(ptr_int1); => Syntax error

	void* ptr_void1 = ptr_int1;
	double* ptr_double1 = static_cast<double*>(ptr_void1);

	cout << "\nptr_int: " << *ptr_int
		<< "\nptr_double: " << *ptr_double << endl;


	////////////////////////////////////////////////////////////////////////////////
	// Case #3. How to use with reference and some pitfalls.
	int val_int = 10;
	//double& ref_double0 = val_int; // => Syntax error
	//double& ref_double1 = static_cast<double&>(val_int); // => Syntax error
	//double& ref_double2 = static_cast<double>(val_int); // => Syntax error
	//double& ref_double3 = (double&)val_int; // => Runtime error
	//ref_double3 = 20;

	const double& ref_double4 = static_cast<double>(val_int);
	double&& ref_double5 = static_cast<double>(val_int);

	ref_double5 = 20;

	cout << "\nCase #3\nval_int: " << val_int
		<< "\nref_double5: " << ref_double5 << endl;

	double x1 = 44;
	const double x2 = 59;

	const double& x3 = 50;
	const double& x4 = x2;
	const double& x5 = x1;

	//x3 += 1; // Errors
	//x4 += 1;
	//x5 += 1;

	////////////////////////////////////////////////////////////////////////////////


	int x = 10; // x - lvalue, 10 - rvalue
	int& y = x;  // y - lvalue, x - lvalue
	int z = x + y; // z - lvalue, x - lvalue, y - lvalue, (x + y) - rvalue
	//int& w = x + y; // Compilation error, because (x + y) - rvalue


	class AA {

	};

	AA a;

	class A
	{
	public:
		A();         //Обычный конструктор
		A(const A&); //Конструктор копирования
		A(A&&);      //Конструктор перемещения
	};

	cout << sizeof(A) << endl;


}


template<class T>
typename remove_reference<T>::type&& my_move(T&& _Arg)
{
	return (static_cast<typename remove_reference<T>::type&&>(_Arg));
}

void casts_operators_explore() {

	static_cast_operator();

}