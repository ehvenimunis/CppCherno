// ClassVsStruct.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
#include <iostream>
using namespace std;

// Program 1
// CPP Program to demonstrate that Members of a class are private by default
class TestClass { 
	// x is private
	int x;
};

// Program 2
// CPP Program to demonstrate that members of a structure are public by default.
struct TestStruct {
	// x is public
	int x;
};

// Program 3
// C++ program to demonstrate Inheritance in class
// Base class
class Parent {
public:
	int x;
};

// Sub class inheriting from Base Class(Parent)
class Child : public Parent {
public:
	int y;
};

// Program 4
// C++ program to demonstrate Inheritance in structure
struct Base {
public:
	int x;
};

struct Derived : Base {
public:
	int y;
}; // Is equivalent to struct Derived : public Base {}

// Driver Code
int main()
{
	// Program 1
	TestClass t;
	// t.x = 20;
	// compiler error because x is private



	// Program 2
	TestStruct y;
	y.x = 20;
	// works fine because x is public
	cout << y.x;
	


	// Program 3
	Child obj1;
	// An object of class child has all data members and member functions of class parent
	obj1.y = 777;
	obj1.x = 999;
	cout << endl << obj1.y << endl;
	cout << obj1.x << endl;



	// Program 4
	Derived d;
	d.x = 88; // Works fine because inheritance is public
	cout << d.x;

	getchar();

	return 0;
}


/*

20
777
999
88

*/


