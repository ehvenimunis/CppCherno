#include <iostream>
using namespace std;

void ArttirVeYazdir()
{
	static int s_degisken = 1;
	// Degisken statiktir.

	++s_degisken;
	std::cout << s_degisken << std::endl;

} // s_degisken yok edilmedi.

auto topla(int x, int y)
{
	return x + y;
}

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
	cout << "Declerated Variable : " << a123 << endl;


	//STATIC
	std::cout << "\nStatic variable values : " << std::endl;
	ArttirVeYazdir();
	ArttirVeYazdir();
	ArttirVeYazdir();

	// AUTO
	auto x{5.6}; //Compailer know type of x is double!
	std::cout << "\nAuto value :" << x << std::endl;
	std::cout << "5 + 5 = " << topla(5, 5) << std::endl; //Return type can auto for function!

	// Ýkilik, sekizlik ve on altýlýk sayý sabitleri
	int aa = 0b01011001;
	int bb = 0765;
	int cc = 0xFF;


	// CONST
	const double gravity{ 9.8 }; // Dogrudur ve tercih edilir.
	double const PI{ 3.14 }; // Calisir ama onerilmez.

	int age = 55;
	const int userAgeVarible(age); // Defines and get first value 


	// CHANGE TYPE
	int myInt{ 12 };
	long myLong;
	myLong = myInt;

	// static_cast
	char c = 'a';
	std::cout << "\nStatic Cast :" << std::endl << static_cast<char>(c) << std::endl; // a yazdýrýr.
	std::cout << static_cast<int>(c) << std::endl; // a deðil 97 yazdýrýr.


	return 0;
}
