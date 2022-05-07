// dynamicCast.cpp

#include <iostream>

using namespace std;

void printf(char* p)
{
    cout << "char * " << p << endl;
}

class Animal
{

public:

    virtual void typeName() { cout << "Type Name : Animal" << endl; };
};

class Lion : public Animal
{
public:
    virtual void typeName() { cout << "Type Name : Lion" << endl; };

};

int main(int argc, char** argv)
{
    Animal* h1 = new Animal();
    Animal* h2 = new Lion(); //burada aslında gizli bir tür dönüştürme işlemi var. Yine burda da dynamic_cast operatörü kullanılabilir.
    Animal* h3;

    // DYNAMİC CAST

    if ((h3 = dynamic_cast<Lion*>(h1)) == NULL) // h1 göstericisi Animal türüne ait bir gösterici olduğundan dynamic_cast operatörü NULL dönecektir.
        cout << "h1 Lion cant change" << endl;

    if ((h3 = dynamic_cast<Lion*>(h2)) == NULL)
        cout << "h2 Lion cant change" << endl;

    h3->typeName();

    delete(h1);
    delete(h2);



    // STATİC CAST
    Animal* h4 = new Animal();
    Animal* h5 = new Lion();
    Animal* h6;

    h6 = static_cast<Lion*>(h4); //static_cast operatörüyle Animal* türünden bir nesne Lion* ’a dönüştürülerek yine Lion* türünden bir göstericiye atanmıştır. 

    /*
        Çalışma zamanında bu kodun ne yapacağı belirsizdir(ambiguity). Bunun haricinde bu operatörle derleyici tarafından gizli(implicit)
        bir şekilde yapılan tüm tür dönüştürmelerini de yapabilirsiniz.
    */

    h6->typeName();

    delete(h4);
    delete(h5);

    // CONST CAST 
    const char *s = "salih";

    char* p = const_cast<char*>(s);
    /*
        Görüldüğü üzere const olan bir nesnenin normalde const olmayan bir nesneye atanması mümkün değil.Bu tür dönüştürme operatörü ile mümkün hale geliyor.
    */

    printf(p);


    // REINTERPRET CAST
    int a = 5;

    unsigned int* b = reinterpret_cast<unsigned int*>(&a + 1);
    /*
        Her türlü gösterici türünü  her türlü  gösterici türüne çevirebilir. Bilinçsiz kullanımı kesinlikle tavsiye edilmez. Aslında basit olarak
        göstericinin diğer göstericiye binary olarak kopyalanmasıdır.
    */

    cout << *b << endl;

    return 0;
}
