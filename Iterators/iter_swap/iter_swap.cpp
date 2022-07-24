#include <random>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

template<class ForwardIt>
void selection_sort(ForwardIt begin, ForwardIt end)
{
    for (ForwardIt i = begin; i != end; ++i)
        std::iter_swap(i, std::min_element(i, end));
}

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(-9, +9);
    std::vector<int> v;
    std::generate_n(back_inserter(v), 20, bind(dist, gen));

    std::cout << "Before sort: " << std::showpos;
    for (auto e : v) std::cout << e << ' ';

    selection_sort(v.begin(), v.end());

    std::cout << "\nAfter sort : ";
    for (auto e : v) std::cout << e << ' ';
    std::cout << '\n';
}

/*

    Before sort: -9 -2 -6 -1 -2 +8 -3 +0 -9 -5 +3 +2 +4 +6 -7 +0 +0 +2 -3 +6
    After sort : -9 -9 -7 -6 -5 -3 -3 -2 -2 -1 +0 +0 +0 +2 +2 +3 +4 +6 +6 +8

*/