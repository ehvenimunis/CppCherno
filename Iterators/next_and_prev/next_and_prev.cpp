// next_and_prev.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <list>
#include <algorithm>
#include <iterator>
#include <iostream>

int main()
{
	std::list<int> ilist{ 5, 56, 7, 48, 11, 23, 37, 49 };
	for_each(next(ilist.begin()), prev(ilist.end()), [](int&3 r) {r *= 2; });

	/*
		next(ilist.begin()) ifadesi ile ilist kabında tutulan ikinci öğenin konumunu
		prev(ilist.end()) ifadesi ile kapta tutulan son öğenin konumunu elde ediyoruz. 
		
		for_each algoritmasıyla ilist listesindeki ilk ve son öğe haricindeki tüm öğeleri 2 katına çıkartmış olduk.
	*/

	for (int i : ilist)
		std::cout << i << " ";

	std::cin.get();
}

/*

	5 112 14 96 22 46 74 49

*/