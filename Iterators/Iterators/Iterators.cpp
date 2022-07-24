// Iterators.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <vector>
#include <unordered_map>

int main()
{
    std::vector<int> values = { 1, 2, 3, 4, 5 };

    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i] << " ";
    }
    std::cout << std::endl;

    /********************************************************************************/
    for (int value : values)
        std::cout << value << " ";
    std::cout << std::endl;

    /********************************************************************************/
    for (std::vector<int>::iterator it = values.begin(); 
        it != values.end(); it++) 
    {
        std::cout << *it << " " ;
    }

    /********************************************************************************/
    using ScoreMap = std::unordered_map<std::string, int>;
    //using ScoreMapConstIter = ScoreMap::const_iterator;
    ScoreMap map;
    map["Salih"] = 10;
    map["Mery"] = 100;

    std::cout << std::endl;
    for (ScoreMap::const_iterator it = map.begin(); it != map.end(); it++)
    {
        auto& key = it->first;
        auto& value = it->second;
        std::cout << key << " = " << value << std::endl;
    }

    std::cout << std::endl;
    for (auto kv : map) {
        auto& key = kv.first;
        auto& value = kv.second;

        std::cout << key << " = " << value << std::endl;
    }

    std::cout << std::endl;
    for (auto [a, b] : map)
        std::cout << a << " = " << b << std::endl;

    /********************************************************************************/

    std::cin.get();

}

