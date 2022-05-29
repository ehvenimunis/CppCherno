// deleter olarak std::function sınıf şablonunu kullanıyoruz

#include <iostream>
#include <memory>
#include <string>
#include <functional>

class A {
public:
    A() { std::cout << "A ctor\n"; }
    ~A() { std::cout << "A dtor\n"; }
    //...
}; 

struct ADeleter {
    void operator()(A* p)const
    {
        std::cout << p << "adresindeki nesne delete ediliyor\n";
        delete p;
    }
}; 

void fdel(A* p)
{
    std::cout << p << "adresindeki nesne delete ediliyor\n";
    delete p;
}

auto f = [](A* p) {
    std::cout << p << " adresindeki nesne delete ediliyor\n";
    delete p; }; 

    // Şablon eş isim bildirimine dikkat ediniz. Bu bildirim ile T bir tür olmak üzere,
    template<typename T>
    using UniquePtr = std::unique_ptr<T, std::function<void(T*)>>;  // “deleter” olarak function sınıfının kullanılması ile artık uygun parametrik yapıda işlev sağlayan herhangi bir çağrılabilir varlık (callable) kullanılabilir hale geliyor.
    
    
    
int main()
{
    {
       UniquePtr<A> uptr1(new A, fdel);
       UniquePtr<A> uptr2(new A, f);
       UniquePtr<A> uptr3(new A, ADeleter());
    }
    std::cout << "main devam ediyor\n";
    //...


    // Özel bir deleter kullanılmadığı sürece bir unique_ptr nesnesinin bellekte kapladığı yer bir gösterici kadardır. 
    std::cout << sizeof(int*) << "\n";
    std::cout << sizeof(std::unique_ptr<int>) << "\n";
}

/*

    A ctor
    A ctor
    A ctor
    0000017BA11B8750adresindeki nesne delete ediliyor
    A dtor
    0000017BA11C3630 adresindeki nesne delete ediliyor
    A dtor
    0000017BA11C35F0adresindeki nesne delete ediliyor
    A dtor
    main devam ediyor
    8
    8

*/