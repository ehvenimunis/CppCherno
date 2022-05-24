// unique_ptrA.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
// C++ program to illustrate the use of unique_ptr
#include <iostream>
#include <memory>
using namespace std;

class A {
public:
	void show()
	{
		cout << "A::show()" << endl;
	}
};

int main()
{
	unique_ptr<A> p1(new A); // bir unique_ptr nesnesine ilk değer veriliyor.
	p1->show();

	// returns the memory address of p1
	cout << p1.get() << endl;

	// transfers ownership to p2
	unique_ptr<A> p2 = move(p1);
	p2->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;

	// transfers ownership to p3
	unique_ptr<A> p3 = move(p2);
	p3->show();
	cout << p1.get() << endl;
	cout << p2.get() << endl;
	cout << p3.get() << endl;

	A* p4 = p3.release(); // p3 sahipliği bırakıyor.
	cout << p3 << endl;
	cout << p4 << endl;
	

	/*************************************************************************************/


	// unique_ptr nesnesine dinamik bir string nesnesi ile ilkdeğer veriliyor:
	unique_ptr<string> uptr(new string("Maya"));
	(*uptr)[0] = 'K'; // Kaynaktaki yazının ilk karakteri değiştiriliyor
	uptr->append("can"); // Kaynağa karakterler ekleniyor.
	cout << endl << endl << *uptr << endl; // Kaynakta ne varsa yazdırır


	/* Sınıfın bool türüne dönüşüm yapan üye işleviyle bir unique_ptr nesnesinin bir kaynağa sahip olup olmadığı sınanabilir.*/
	if (uptr) { // uptr bir kaynağa sahip ise
		cout << "Class have a source!" << endl;
		uptr = nullptr; // or uptr.reset();
	}

	// unique_ptr nesnesine nullptr değeri doğrudan atanabileceği gibi bu amaçla sınıfın reset isimli üye işlevi de çağrılabilir
	p1.reset();
	p2.reset();
	p3.reset(); // unique_ptr nesnesi bir dinamik nesneye sahipse sahip olduğu dinamik nesneyi delete eder.

	if (uptr) { // uptr bir kaynağa sahip ise
		cout << "Class have a source at now!" << endl;
		cout << *uptr << endl;
	}
	else {
		cout << "Class have not a source at now!" << endl << endl;
	}

	/*************************************************************************************/


	return 0;
}

/*
	A::show()
	000002B72574EE20
	A::show()
	0000000000000000
	000002B72574EE20
	A::show()
	0000000000000000
	0000000000000000
	000002B72574EE20
	0000000000000000
	000002B72574EE20


	Kayacan
	Class have a source!
	Class have not a source at now!
*/