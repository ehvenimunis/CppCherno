// Storage Class.cpp
#include <iostream>
using namespace std;

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

    cout << number << " \n";
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
    mutable int mutable_number;

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
    cout << "Mutable number : " << testClass.mutable_number << endl;

    // aşağıdaki kod bloğu çalışmayacaktır.
    // t1.number = 63;

    cout << "Non-Mutable number : " << testClass.number << endl;

    return 0;
}