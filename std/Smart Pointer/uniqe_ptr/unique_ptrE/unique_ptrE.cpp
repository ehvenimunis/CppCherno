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
}