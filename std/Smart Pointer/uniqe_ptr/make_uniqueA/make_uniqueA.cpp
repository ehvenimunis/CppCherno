// make_uniqueA.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <memory>
#include <string>
#include <iostream>
int main()
{

	auto up = std::make_unique<std::string>(10, 'A'); // İşleve kontrol edilecek dinamik nesnenin kurucu işlevinin kullanacağı argümanlar gönderiliyor.
	std::cout << *up << "\n";
	//...

	/*
	Yukarıdaki kodda make_unique işlev şablonundan üretilecek bir işlevle string sınıfının size_t ve char parametreli kurucu işlevine 10 ve ‘A’ değerleri gönderilerek önce dinamik ömürlü bir string nesnesi hayata getiriliyor. Daha sonra, hayata gelen nesneyi kontrol eden bir unique_ptr nesnesi geri döndürülüyor.
	*/
}

/*

AAAAAAAAAA

*/