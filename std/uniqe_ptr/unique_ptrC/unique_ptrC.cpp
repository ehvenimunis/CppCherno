// unique_ptrC.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <memory>
#include <utility>

struct Widget {
    Widget(int) {}
};

void sink(std::unique_ptr<Widget> uniqPtr) {
    // do something with uniqPtr
}


class Myclass {
    //...
};

std::unique_ptr<Myclass> source()
{
    std::unique_ptr<Myclass> ptr(new Myclass); // ptr dinamik nesnenin sahibi
    ///
    return ptr; // sahiplik çağıran işleve devrediliyor.
}

int main() {

    /*
        1) Bir işlev bir veri boşaltım havuzu (sink) olarak kullanılabilir.
    */

    auto uniqPtr = std::make_unique<Widget>(1998);

    sink(std::move(uniqPtr));           // uniqPtr nesnesi sahipliği bırakır. nesnenin sahiplendiği dinamik ömürlü nesne delete edilir:
    // sink(uniqPtr);                   // ERROR



    /*
        2) Bir işlev nesne üretecek bir kaynak (factory) olarak davranabilir.
    */
    std::unique_ptr<Myclass> p;
    for (int i = 0; i < 10; ++i) {
        p = source(); //p geri döndürülen nesnenin sahipliğini alır 
       //f işlevinin geri döndürdüğü bir önceki nesne silinir
    }
    // p'nin son sahip olduğu nesne silinir.
    /*
        source işlevi her çağrıldığında new ifadesi ile bir Myclass nesnesi oluşturulur ve source işlevi bu nesnenin sahipliğini kendisini çağıran koda devreder. 
        İşlevin geri dönüş değerinin p isimli unique_ptr nesnesine atanması ile kaynağın mülkiyeti işlevi çağıran koda devredilir. 
        Döngünün ikinci ve daha sonraki turlarında p nesnesine yapılan her atama p’nin daha önce sahiplendiği dinamik nesneyi delete eder.
        g işlevinin çıkışında p nesnesinin ömrü sona erdiğinden p için çağrılan sonlandırıcı işlev p’nin sahipliğini üstlendiği son Myclass nesnesinin de 
        delete edilmesini sağlar. Bir kaynak sızıntısı mümkün değildir. İşlev içinden bir hata nesnesi gönderilse dahi, unique_ptr nesnesinin sahibi olduğu 
        dinamik nesne delete edilecektir.
    */

}