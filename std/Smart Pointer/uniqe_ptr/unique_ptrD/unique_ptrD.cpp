// unique_ptrD.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
// Making delete process with three diffrent type

#include <iostream>
#include <memory>
#include <string>

//1
class A {
public:
    A() { std::cout << "A ctor\n"; }
    ~A() { std::cout << "A dtor\n"; }
    //...
}; 

//2
void fdel(A* p)
{
    /*  
        Deleter olarak kullandığımız global fdel isimli fonksiyon,
        delete işleminden önce delete edilecek nesnenin adresini standart çıkış akımına yazdırıyor. 
    */
    std::cout << p << " adresindeki nesne delete ediliyor\n";
    delete p;
}

//3 kendimiz de bir fonksiyon sınıfı (functor class) oluşturalım
struct ADeleter {
    void operator()(A* p)const
    {
        std::cout << p << " adresindeki nesne delete ediliyor\n";
        delete p;
    }
};

int main()
{

    //1
    {
        std::unique_ptr<A, void(*)(A*)> up2(new A, &fdel);
    }    
    std::cout << "main devam ediyor\n";

    //2
    auto f = [](A* p) { std::cout << p << " adresindeki nesne delete ediliyor\n"; delete p; };
    {
        std::unique_ptr<A, decltype(f)> up1(new A, f); // lambda ifadesine ilişkin kapanış sınıfının (closure type) tür bilgisi için decltype belirtecinin kullanımına dikkat ediniz.
    }

    //3 
    {
        std::unique_ptr<A, ADeleter> up3(new A);
    }
}

/*

    A ctor
    0000020618353550 adresindeki nesne delete ediliyor
    A dtor
    main devam ediyor

*/