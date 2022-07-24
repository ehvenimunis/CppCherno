// mode_iterator.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <iterator>
#include <numeric>
#include <string>

int main()
{
    std::vector<std::string> v{ "this", "_", "is", "_", "an", "_", "example" };

    auto print_v = [&](auto const rem) {
        std::cout << rem;
        for (const auto& s : v)
            std::cout << std::quoted(s) << ' ';
        std::cout << '\n';
    };

    print_v("Old contents of the vector: ");

    std::string concat = std::accumulate(std::make_move_iterator(v.begin()),
        std::make_move_iterator(v.end()),
        std::string());

    print_v("New contents of the vector: ");

    std::cout << "Concatenated as string: " << quoted(concat) << '\n';
}

/*

    Old contents of the vector : "this" "_" "is" "_" "an" "_" "example"
    New contents of the vector : "" "" "" "" "" "" ""
    Concatenated as string : "this_is_an_example"

*/