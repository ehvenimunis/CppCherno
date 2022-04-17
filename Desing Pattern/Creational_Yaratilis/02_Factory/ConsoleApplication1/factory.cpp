#include <iostream>

using namespace std;

// enum, kullanım aşamalarımız sabit ve kullanışlı olması amacı ile yazılmıştır.
enum AracTipi
{
    Tren_T,
    Araba_T,
    Ucak_T
};

// Abstract sınıf
class Arac
{
public:
    virtual void aracSesCikar() = 0;
    static Arac* create(AracTipi);
};

// Inheritence
class Ucak : public Arac
{
public:
    void aracSesCikar() override
    {
        cout << "Vuuuuuuuuuuh Vuuuuuuh" << endl;
    }
};

class Tren : public Arac
{
public:
    void aracSesCikar() override
    {
        cout << "Çuuuf Çuuuuuf" << endl;
    }
};

class Araba : public Arac
{
public:
    void aracSesCikar() override
    {
        cout << "Vııın Vııın" << endl;
    }
};


// Soyut sınıfımızda olan "create" methodumuzu tanımlıyoruz.
Arac* Arac::create(AracTipi tip)
{
    if (tip == Tren_T)
    {
        return new Tren();
    }
    else if (tip == Araba_T)
    {
        return new Araba();
    }
    else if (tip == Ucak_T)
    {
        return new Ucak();
    }
    else
    {
        return NULL;
    }
}

int main()
{
    AracTipi tip = Ucak_T;
    Arac* aracPtr = Arac::create(tip);
    aracPtr->aracSesCikar();

    delete[] aracPtr;
    return 0;
}

// Oluşturulan sınıfları, sadece istediğimiz yötemler ile kontrol etmiş olduk. 