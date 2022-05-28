// weak_ptrA.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <memory>

using namespace std;

class B;

class A
{
    shared_ptr<B> sP1; // use weak_ptr instead to avoid CD

public:
    A() { cout << "A()" << endl; }
    ~A() { cout << "~A()" << endl; }

    void setShared(shared_ptr<B>& p)
    {
        sP1 = p;
    }
};

class B
{
    shared_ptr<A> sP1;

public:
    B() { cout << "B()" << endl; }
    ~B() { cout << "~B()" << endl; }

    void setShared(shared_ptr<A>& p)
    {
        sP1 = p;
    }
};

int main()
{
    shared_ptr<A> aPtr(new A);
    shared_ptr<B> bPtr(new B);

    aPtr->setShared(bPtr);
    bPtr->setShared(aPtr);

    return 0;
}

/*

    A()
    B()

*/

/*

    Çıktıdan görebildiğimiz gibi, A ve B işaretçisinin asla silinmemesi ve dolayısıyla bellek sızıntısı.

    Bu tür bir sorunu önlemek için, A anlamında, daha anlamlı olan shared_ptr yerine A sınıfında kullanın.

    Eğer yukarıda A sınıfında weak_ptr kullanılırsa destructor her iki sınıf nesnesi için de çalışır. 

*/