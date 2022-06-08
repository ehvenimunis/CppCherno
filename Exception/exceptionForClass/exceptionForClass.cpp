// exceptionForClass.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
// C++ Program to demonstrate a catching of
// Derived exception and printing it successfully
#include <iostream>
using namespace std;

class Base {};
class Derived : public Base {};
int main()
{
	Derived d;
	// Some other functionalities
	try {
		// Monitored code
		throw d;
	}
	catch (Derived d) {
		cout << "Caught Derived Exception";
	}
	catch (Base b) {
		cout << "Caught Base Exception";
	}
	getchar(); // To read the next character
	return 0;
}



/*

If both base and derived classes are caught as exceptions, then the catch block of the derived class must appear before the base class. 
If we put the base class first then the derived class catch block will never be reached. For example, the following C++ code prints “Caught Base Exception“
*/
