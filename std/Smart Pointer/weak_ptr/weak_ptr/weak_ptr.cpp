// weak_ptr.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.

/*
  std::weak_ptrsarkan işaretçi problemini çözmek için çok iyi bir yoldur. Sadece ham işaretçiler kullanılarak, referans alınan verinin yerinin değiştirilip değiştirilmediğini bilmek mümkün değildir. Bunun yerine, bir std::shared_ptr veriyi yönetmesine izin vererek ve veri kullanıcılarına std::weak_ptr sağlayarak, kullanıcılar expired() veya lock() öğesini çağırarak verilerin geçerliliğini kontrol edebilir.

  Bunu yalnızca std::shared_ptr ile yapamazsınız, çünkü tüm std::shared_ptr örnekleri, tüm std::shared_ptr örnekleri kaldırılmadan önce kaldırılmayan verilerin sahipliğini paylaşır. lock() kullanarak sarkan işaretçisinin nasıl kontrol edileceğine bir örnek:
*/

#include <iostream>
#include <memory>

int main()
{
    // OLD, problem with dangling pointer
    // PROBLEM: ref will point to undefined data!

    int* ptr = new int(10);
    int* ref = ptr;
    delete ptr;

    // NEW
    // SOLUTION: check expired() or lock() to determine if pointer is valid

    // empty definition
    std::shared_ptr<int> sptr;

    // takes ownership of pointer
    sptr.reset(new int);
    *sptr = 10;

    // get pointer to data without taking ownership
    std::weak_ptr<int> weak1 = sptr;

    // deletes managed object, acquires new pointer
    sptr.reset(new int);
    *sptr = 5;

    // get pointer to new data without taking ownership
    std::weak_ptr<int> weak2 = sptr;

    // weak1 is expired!
    if (auto tmp = weak1.lock())
        std::cout << *tmp << '\n';
    else
        std::cout << "weak1 is expired\n";

    // weak2 points to new data (5)
    if (auto tmp = weak2.lock())
        std::cout << *tmp << '\n';
    else
        std::cout << "weak2 is expired\n";
}

/*
    weak1 is expired
    5
*/