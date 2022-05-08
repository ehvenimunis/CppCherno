#include <iostream>
#include <vector>
#include <type_traits>


/*

Türden bağımsız (generic) olarak yazılan kodlarda, bazı durumlarda bir ifadenin türünün derleme zamanında derleyici tarafından yapılacak bir çıkarımla anlaşılması gerekiyor. decltype c++11 ile gelen bir özellik. Temel olarak değişkenin tipini belirlemeye yarıyor fakat auto gibi değil. auto kelimesi oldukça sınırlıdır. python "type(değişken)" ifadesi gibi çalışıyor.

*/
class A
{
public:
    int memberFunction(double);
    double x;
};
const A* a;

// y'nin tipi double (nasil tanimlandiysa oyle)
decltype(a->x) y;

// Parantez kullanımı: 
// z'nin tipi double&. Neden boyle? Cunku ekstra eklenen parantezler
// ifadeyi l value expression'a ceviriyor
decltype((a->x)) z = y;

// Asagida donus tipi de, template parametrelerinin tipinden otomatik olarak belirlenebiliyor
// Donus degerinin otomatik atanmasi C++ 14 ile sunuluyor, aklinizda bulunsun
template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u)

{
    return t + u;
}

int main()
{
    int i = 33;
    decltype(i) j = i * 2;

    // Konteynerler ile de kullanabilirsiniz
    // Bu durumda: vector<double>
    std::vector<decltype(a->x)> vi;

    // Sinif uyesi fonksiyonlarin tipleri icin de kullanabilirsiniz
    // int A::(*)(double)
    using memberFunctionPointer = decltype(&A::memberFunction);

    std::cout << "i = " << i << ", "
        << "j = " << j << '\n'
        << "Toplama (int, float): " << add<float, int>(10.5F, 5) << '\n'
        << "Toplama (int, int): " << add<int, int>(10.5F, 5) << '\n';

    auto f = [](int a, int b) -> int
    {
        return a * b;
    };

    // Benzer sekilde lambda tiplerini de bu anlamda kullanabiliyoruz
    decltype(f) g = f;
    i = f(2, 2);
    j = g(3, 3);

    std::cout << "i = " << i << ", "
        << "j = " << j << '\n';

    return 0;
}


/*

    i = 33, j = 66
    Toplama (int, float): 15.5
    Toplama (int, int): 15
    i = 4, j = 9

*/