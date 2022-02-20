// Constructor

/*
    Nesne ne zaman hayata başlarsa constructor o zaman çağırılıyor.
*/

#include <iostream>

using namespace std;

class Myclass {

public:
    Myclass();
};

Myclass::Myclass()
{
    cout << "Myclass default constructor" << endl;
}

void func()
{
    Myclass m, m1; // stack yer alan, default contructor cagirilacak, hem m1 hemde m2 icin cagirilacak ayri ayri
}

void localFunc()
{
    static Myclass m;  //statik yerel sinif nesneleri icin
    //eger bu fonksiyon cagrilmazsa m hayata gelmez
}

void func_A()
{
    static Myclass m;
}

Myclass g; // global bir nesne, ömrü static 
           // static omurlu nesneler main den önce cagirilirlar

int main()
{
    cout << "main start" << endl << endl;

    for (int k = 0; k < 2; k++)
        func();

    Myclass m1; // 1 kere constructor cagirilir
    // Myclass default constructor
    Myclass& r1 = m1; // referans demek nesne demek degil
    Myclass& r2 = m1; // referans bir nesnenin yerine gecen isim

    Myclass* ptr; // constructor cagrisi yok, bu bir pointer, bir instance  olusturulmadigi surece constructorin cagrisina neden olmaz

    std::cout << endl << "***************" << endl << endl;

    Myclass a[10]; // 10 kere constructor cagirilacak, her elemani icin




    cout << endl << endl << "main tekrar basliyor" << endl;
    cout << "func cagriliyor " << endl;
    func_A(); // constructor cagirilacak
    cout << "main devam ediyor" << endl;
    cout << "func bir kez daha cagriliyor " << endl;
    func_A(); // contructor yazisi cikmaz, artik 2. kez cagirdigimizda hayata gelmiyor
    // static nesneler hayata 1 kere gelir
    cout << "func bir kez daha cagriliyor " << endl;
    func_A();




    return 0;
}
/*
Myclass default constructor
Myclass default constructor
Myclass default constructor
Myclass default constructor
….
*/