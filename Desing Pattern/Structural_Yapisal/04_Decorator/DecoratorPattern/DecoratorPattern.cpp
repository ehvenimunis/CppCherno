//============================================================================
// İsim        : 04_Decorator
// Yazan       : Salih Aydoğan
// Version     : 1.0
// Copyright   : 
// Açıklama    : Decorator Pattern
//============================================================================
#include <string>
#include <iostream>
using namespace std;

/*
    İlk adım olarak soyut bir sınıf oluşturuyoruz. Bizim sınıfımızın ismi "Araba" olarak belirledik.
*/
class Araba // Abstract
{
protected:
    string aciklama;

public:
    Araba()
    {
        aciklama = "Bilinmeyen Araba";
    }

    virtual string getAciklama()
    {
        return aciklama;
    }

    virtual double getFiyat() = 0;

    virtual ~Araba()
    {
        cout << "~Araba()\n";
    }
};

/* Bu sınıf, bir arabaya özelliklik ekleme için oluşturulmuş soyut bir sınıftır. */
class SecenekDecorator : public Araba // Decorator
{
public:
    virtual string getAciklama() = 0;

    virtual ~SecenekDecorator()
    {
        cout << "~SecenekDecorator()\n";
    }
};

/* Bu sınıf ana hattımızı, ürünümüzü belirtiyor. */
class ArabaModel1 : public Araba
{
public:
    ArabaModel1()
    {
        aciklama = "Fiat Egea";
    }
    virtual double getFiyat() override
    {
        return 56000.23;
    }

    ~ArabaModel1()
    {
        cout << "~ArabaModel1()\n";
    }
};

/*
Ardından "SecenekDecorator" sınıfından türetilen özellikleri oluşturuyoruz. İstediğimiz kadar özellik böylece "SecenekDecorator" sınıfı sayesinde ana hattımıza ekleyebilecek durumda olacağız. Biz proje kapsamında aracımıza "Navigasyon", "SesSistemi", "OtomatikVites" özelliklerini ekledik.
*/
class Navigasyon : public SecenekDecorator
{
    Araba* araba;

public:
    Navigasyon(Araba* araba)
    {
        this->araba = araba;
    }
    string getAciklama() override
    {
        return araba->getAciklama() + ", Navigasyon";
    }

    double getFiyat() override
    {
        return 300.56 + araba->getFiyat();
    }
    ~Navigasyon()
    {
        cout << "~Navigasyon()\n";
        delete araba;
    }
};

class SesSistemi : public SecenekDecorator
{
    Araba* araba;

public:
    SesSistemi(Araba* araba)
    {
        this->araba = araba;
    }
    string getAciklama() override
    {
        return araba->getAciklama() + ", Süper ses sistemi";
    }

    double getFiyat() override
    {
        return 250.60 + araba->getFiyat();
    }
    ~SesSistemi()
    {
        cout << "~SesSistemi()\n";
        delete araba;
    }
};

class OtomatikVites : public SecenekDecorator
{
    Araba* araba;

public:
    OtomatikVites(Araba* araba)
    {
        this->araba = araba;
    }
    string getAciklama() override
    {
        return araba->getAciklama() + ", Otomatik Vites";
    }

    double getFiyat() override
    {
        return 5450.25 + araba->getFiyat();
    }
    ~OtomatikVites()
    {
        cout << "~OtomatikVites()\n";
        delete araba;
    }
};

int main()
{
    // Boş araba yaratıyoruz
    Araba* araba = new ArabaModel1();
    cout << "Araba Modeli " << araba->getAciklama() << " fiyatı " << araba->getFiyat() << "₺\n";

    // Arabaya özellik ekliyoruz. Bir nesneye dinamik olarak özellik eklemektir.
    araba = new Navigasyon(araba);
    cout << araba->getAciklama() << " özelliği fiyatı " << araba->getFiyat() << "₺\n";

    araba = new SesSistemi(araba);
    cout << araba->getAciklama() << " özelliği fiyatı " << araba->getFiyat() << "₺\n";

    araba = new OtomatikVites(araba);
    cout << araba->getAciklama() << " özelliği fiyatı " << araba->getFiyat() << "₺\n";

    cout << "----------------------------------------------" << endl;

    delete araba;

    return 0;
}


/*

    Araba Modeli Fiat Egea fiyat² 56000.2?
    Fiat Egea, Navigasyon ÷zelli­i fiyat² 56300.8?
    Fiat Egea, Navigasyon, S³per ses sistemi ÷zelli­i fiyat² 56551.4?
    Fiat Egea, Navigasyon, S³per ses sistemi, Otomatik Vites ÷zelli­i fiyat² 62001.6?
    ----------------------------------------------
    ~OtomatikVites()
    ~SesSistemi()
    ~Navigasyon()
    ~ArabaModel1()
    ~Araba()
    ~SecenekDecorator()
    ~Araba()
    ~SecenekDecorator()
    ~Araba()
    ~SecenekDecorator()
    ~Araba()

*/