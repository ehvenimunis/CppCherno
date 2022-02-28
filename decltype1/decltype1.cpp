#include <iostream>
#include <type_traits>
#include <cstdint>

int main()
{
    int i = 33;
    decltype(i) j = i * 2;
    std::cout << std::boolalpha;

    std::cout << "i and j same type? "
        << std::endl << std::is_same_v<decltype(i), decltype(j)> << '\n';

    // int 32 bit ise true
    std::cout << std::endl << std::is_same<int, std::int32_t>::value << ' ' << '\n';

    // dogru degil
    std::cout << std::is_same<int, short>::value << ' ' << '\n';

    // simdi bir de degiskenleri karsilastiralim
    long double num1 = 1.0;
    long double num2 = 2.0;
    std::cout << std::is_same_v<decltype(num1), decltype(num2)> << '\n';

    return 0;
}


/*

i and j same type?
true

true
false
true

*/