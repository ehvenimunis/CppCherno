﻿// shared_ptrA.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
// C++ program to demonstrate shared_ptr
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
	shared_ptr<A> p1(new A);
	cout << p1.get() << endl;
	p1->show();
	shared_ptr<A> p2(p1);
	p2->show();
	cout << p1.get() << endl; // shared_ptr ile birden fazla pointer aynı kaynağa işaret edebilir.
	cout << p2.get() << endl;

	// Returns the number of shared_ptr objects
	// referring to the same managed object.
	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;

	// Relinquishes ownership of p1 on the object
	// and pointer becomes NULL
	p1.reset();
	cout << p1.get() << endl;
	cout << p2.use_count() << endl; // shared_ptr kullanarak ilgili kaynağı kaç farklı pointer ın işaret ettiğini de öğrenebiliriz (reference counting).
	cout << p2.get() << endl;

	return 0;
}

/*
	00000236A153E340
	A::show()
	A::show()
	00000236A153E340
	00000236A153E340
	2
	2
	0000000000000000
	1
	00000236A153E340
*/