// accumulateExample.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

// C++ program to find sum of all element between
// to K1'th and k2'th smallest elements in array
// C++ program to demonstrate working of accumulate()
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

using namespace std;

// Returns sum between two kth smallest elements of the array
int sumBetweenTwoKth(int arr[], int n, int k1, int k2)
{
	// Sort the given array
	sort(arr, arr + n);

	/* Below code is equivalent to
	int result = 0;
	for (int i=k1; i<k2-1; i++)
	result += arr[i]; */
	return accumulate(arr + k1, arr + k2 - 1, 0);
}

// Driver program
int main()
{
	int arr[] = { 20, 8, 22, 4, 12, 10, 14 };
	int k1 = 3, k2 = 6;
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << sumBetweenTwoKth(arr, n, k1, k2);
	return 0;
}
