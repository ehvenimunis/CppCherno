#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;
using UpStrvec = vector<unique_ptr<string>>;

int main()
{

	// unique_ptr sınıfının get işlevinin geri dönüş değeri kontrol edilen dinamik nesnenin adresi. unique_ptr nesnemizin yaşamını kontrol ettiği bir dinamik nesne yoksa işlev nullptr adresini döndürüyor
	auto up = make_unique<string>(10, 'A'); 
	cout << *up << "\n";
	string* ptr = up.get();
	cout << ptr->size() << "\n";


	/*
	
	auto up1 = make_unique<string>(10, 'A');
	string* ptr1 = up1.get();
	unique_ptr<string> up2(ptr1);

	Yukarıdaki kodda hem up1 hem de up2 nesneleri aynı dinamik string nesnesinin hayatını kontrol eder hale geliyor. Böylece tek sahiplik (exclusive ownwership) ilkesi çiğneniyor. Her iki nesnenin de sonlandırıcı işlevinin aynı dinamik string nesnesini delete etmesi (double deletion) tanımsız davranış oluşturuyor.



	auto up = make_unique<string>(10, 'A');
	string *ptr = up.get();
	delete ptr;

	Yukarıdaki kodda get işlevinden adresi alınan dinamik nesne delete ediliyor. Bu durumda up nesnesinin sarmaladığı gösterici boşa çıkıyor (dangling pointer). up için sonlandırıcı işlev çağrıldığında tanımsız davranış oluşacak.

	*/

	unique_ptr<string> up2{ new string {"meryem"} };    
	UpStrvec myvec;
	myvec.push_back(move(up2));
	myvec.emplace_back(new string{ "salih" });
	myvec.push_back(unique_ptr<string>{new string{ "loves" }});
	myvec.push_back(make_unique<string>(*myvec[0], 1, 5));    // sıfır elemanı "meryem" dir. 1. ve 5. argümanları yazdırır. 
	
	cout << endl;
	for (auto& up2 : myvec)
		cout << *up2 << "\n";


	//

}

/*

	AAAAAAAAAA
	10

	meryem
	salih
	loves
	eryem

*/