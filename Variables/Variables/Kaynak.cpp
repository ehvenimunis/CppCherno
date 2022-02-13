#include <iostream>
using namespace std;

void ArttirVeYazdir()
{
	static int s_degisken = 1;
	// Degisken statiktir.

	++s_degisken;
	std::cout << s_degisken << std::endl;

} // s_degisken yok edilmedi.

int main()
{
	// declaration and definition
	// of variable 'a123'
	char a123 = 'a';

	// This is also both declaration and definition
	// as 'b' is allocated memory and
	// assigned some garbage value.
	float b;

	// New returned a pointer to some address in memory. 
	int* foo = new int;
	std::cout << *foo << std::endl;

	// multiple declarations and definitions
	int _c, _d45, e;

	// Let us print a variable
	cout << a123 << endl;

	std::cout << "\nStatic variable values : " << std::endl;
	ArttirVeYazdir();
	ArttirVeYazdir();
	ArttirVeYazdir();

	return 0;
}
