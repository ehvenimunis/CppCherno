// unique_ptrB.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
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
    // Bir unique_ptr nesnesine başka bir unique_ptr nesnesinin değeri taşınarak atanmalıdır.
    // unique_ptr nesnesi dinamik ömürlü bir nesneyle başlatılıyor.
    unique_ptr<A> up1(new A);
    //Yeni bir unique_ptr nesnesi dinamik ömürlü bir nesneyle başlatılıyor.
    unique_ptr<A> up2(new A);
    up2 = move(up1); // taşıyan atama işlevi ile up2'nin daha önce sahip olduğu nesne sonlandırılır.
    // Sahiplik up1'den up2'ye devredilir.

    cout << "up2 value : " << up2 << endl;
    cout << "up1 value : " << up1 << endl; // Yeni bir sahiplik edinmeden sahip olduğu nesneyi bırakan bir unique_ptr nesnesi hiçbir nesneyi göstermez. 



    // unique_ptr nesnelerine doğrudan adresler atanamaz.
    unique_ptr<A> ptr;
    // ptr = new A; // Geçersiz
    ptr = unique_ptr<A>(new A); // Geçerli. Eski nesne sonlandırılır yenisi sahiplenilir. 
}
