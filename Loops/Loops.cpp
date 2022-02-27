// Loops.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int a, b;
    string c[] = { "","one","two","three","four","five","six","seven","eight","nine" };
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        cout << ((i <= 9) ? c[i] : ((i % 2 == 0) ? "even" : "odd")) << endl;
    return 0;
}


/*
    Sample Input

    8
    11

    Sample Output

    eight
    nine
    even
    odd
*/

