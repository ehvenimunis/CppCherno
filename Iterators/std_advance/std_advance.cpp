// std_advance.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>
#include <iterator>
#include <vector>
/* Increments given iterator it by n elements.  */

int main()
{
    std::vector<int> v{ 3, 1, 4 };

    auto vi = v.begin();
    std::advance(vi, 2);
    std::cout << *vi << ' ';

    vi = v.end();
    std::advance(vi, -2);
    std::cout << *vi << '\n';
}

/*

    4 1

*/