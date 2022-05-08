// PartialSum.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>

/*
Syntax:

		partial_sum(first, last, b);

		or

		partial_sum(first, last, b, myfun);

Parameters:

		first, last: first and last element of range whose elements are to be added
		b: index of array where  corresponding partial sum will be stored
		myfun: a user-defined function for performing any specific task
*/

// C++ program to demonstrate working of partial_sum()
#include <iostream>
#include <numeric>
using namespace std;

// user defined function
int myfun(int x, int y)
{
	// the sum of element is twice of its
	// adjacent element
	return x + 2 * y;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int b[5];

	// Default function
	partial_sum(a, a + 5, b);

	cout << "Partial Sum - Using Default function: ";
	for (int i = 0; i < 5; i++)
		cout << b[i] << ' ';
	cout << '\n';

	// Using user defined function
	partial_sum(a, a + 5, b, myfun);

	cout << "Partial sum - Using user defined function: ";
	for (int i = 0; i < 5; i++)
		cout << b[i] << ' ';
	cout << '\n';

	return 0;
}
