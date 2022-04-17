//============================================================================
// İsim        : AbstractFactory
// Yazan       : Muhammed Salih Aydoğan
// Version     : 1.0
// Copyright   : 
// Açıklama    : Abstract Factory Pattern
//============================================================================
#include <iostream>
using namespace std;

#define DOLAP 1
//#define MASA 1

class Marangoz
{
public:
    virtual void urunTip() = 0; /* override tanımlayıcısını kullanacaksak, burada fonksiyonun virtual olduğunu belirtmek zorundayız */
};

class Masa : public Marangoz
{
public:
    void urunTip() override /* yalnızca virtual fonksiyonları override edebiliriz */
    {
        std::cout << "Masa Yapim Onarim" << std::endl;
    }
};

class Dolap : public Marangoz
{
public:
    void urunTip() override
    {
        std::cout << "Dolap Yapim Onarim" << std::endl;
    }
};

class Fabrika
{
public:
    virtual Marangoz* fabrikaOlustur() = 0; /* override tanımlayıcısını kullanacaksak, burada fonksiyonun virtual olduğunu belirtmek zorundayız */
};

class DolapOlustur : public Fabrika
{
public:
    Marangoz* fabrikaOlustur() override
    {
        return new Dolap;
    }
};

class MasaOlustur : public Fabrika
{
public:
    Marangoz* fabrikaOlustur() override
    {
        return new Masa;
    }
};

int main()
{
    #ifdef DOLAP
    Fabrika* fabrika = new DolapOlustur;
    #elif MASA
    Fabrika* fabrika = new MasaOlustur;
    #endif

    Marangoz* marangoz = fabrika->fabrikaOlustur();
    marangoz->urunTip();

    delete[] fabrika;
    delete[] marangoz;
    return 0;
}

/*
    Ortak bir sınıf türünden türetilecek, farklı nesneler oluşturduk.
    Bu pattern, genel bir deseni takip eden nesneler oluşturmamıza izin veriyor.
    Somut sınıflarını doğrudan belirtmeden, ilgili veya bağımlı nesnelerin ailelerinin oluşturulmasını sağladı.
*/
