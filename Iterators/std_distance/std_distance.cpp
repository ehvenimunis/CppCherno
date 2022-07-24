﻿// std_distance.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <iterator>
#include <vector>

/* Returns the number of hops from first to last. */
int main()
{
    std::vector<int> v{ 3, 1, 4 };
    std::cout << "distance(first, last) = "
        << std::distance(v.begin(), v.end()) << '\n'
        << "distance(last, first) = "
        << std::distance(v.end(), v.begin()) << '\n';
    //the behavior is undefined (until C++11)

    static constexpr auto il = { 3, 1, 4 };
    // Since C++17 `distance` can be used in constexpr context.
    static_assert(std::distance(il.begin(), il.end()) == 3);
    static_assert(std::distance(il.end(), il.begin()) == -3);
}

/*

distance(first, last) = 3
distance(last, first) = -3

*/