// Storage Class.cpp
#include <iostream>
using namespace std;

/*
    Storage Class nedir
    Storage class yapıları: bir fonksiyonun veya değişkenin tanımlanması esnasında, onun amacını, görünürlüğünü ve bellekten ne zaman silineceğini belirten anahtar kelimelerdir. Örnek olarak: Bir değişkenin programın heryerinden erişilebilmesini veya bir değişkenin aynı olmamakla birlikte benzer değerlerinde alabilmeleri storage class anahtar kelimeleri ile sağlanır.

    web: https://thecodeprogram.com/c---ile-storage-siniflari
*/

//auto
void autoClass()
{
    cout << "Auto Class use " << endl;

    auto number = 14;
    auto number2 = 67.9;
    auto yazi = "Thecodeprogram";

    cout << number << " \n";
    cout << number2 << " \n";
    cout << yazi << " \n";

    number = 123.456;

    cout << number << " \n"; // Sadece 123 değerini yazdırır noktadan sonrası olmaz
}

// extern 
int i;
void externClass()
{
    cout << "extern Class example" << endl;

    // değişken extern yapılıyor
    extern int i;

    cout << "Extern i : " << i << endl;

    // Value atanıyor
    i = 33;

    cout << "Value attach i : " << i << endl;
}

//Register 
void registerClass()
{
    cout << "Register Class example" << endl;

    register int number = 33;

    cout << "Defined Value : " << number << endl;
    cout << "Adress : " << &number << endl;
}

//Static example
static int variable = 33;

static int staticMetod()
{
    cout << "Static metod : " << endl;

    static int deger = 0;
    return deger;
}

//Mutable 
class TestClass {
public:
    int number;
    mutable int mutable_number; // mutable

    TestClass()
    {
        number = 123;
        mutable_number = 33;
    }
};

int main()
{
    autoClass();
    externClass();
    registerClass();

    cout << "Static variable : " << staticMetod() << endl;
    cout << "Static variable : " << variable << endl;

    const TestClass testClass;

    testClass.mutable_number = 41;
    cout << "Mutable number : " << testClass.mutable_number << endl; // 41

    // aşağıdaki kod bloğu çalışmayacaktır.
    // t1.number = 63;

    cout << "Non-Mutable number : " << testClass.number << endl; // 123

    return 0;
}

/*

    Auto Class use
    14
    67.9
    Thecodeprogram
    123
    extern Class example
    Extern i : 0
    Value attach i : 33
    Register Class example
    Defined Value : 33
    Adress : 0000005CCE9BF4C4
    Static metod :
    Static variable : 0
    Static variable : 33
    Mutable number : 41
    Non-Mutable number : 123

*/