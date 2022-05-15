//============================================================================
// İsim        : Prototype
// Yazan       : Muhammed Salih Aydogan
// Version     : 1.0
// Copyright   : 
// Açıklama    : Prototype Pattern Topic
//============================================================================
#include <iostream>
#include <unordered_map>
#include <string>
#include <memory>
using namespace std;

/* 
    İlk önce soyut bir sınıf oluşturuyoruz. Bu sınıf bizim temel prototip sınıfımız.
*/
class Kayit
{
public:
    virtual ~Kayit() {}
    virtual void print() = 0;
    virtual unique_ptr<Kayit> clone() = 0;
};

/* 
    Oluşturduğumuz soyut sınıftan somut protatiplerimizi oluşturuyoruz.
*/
class ArabaKayit : public Kayit
{
private:
    string arabaIsim;
    int arabaID;

public:
    ArabaKayit(string arabaIsim, int ID) : arabaIsim(arabaIsim), arabaID(ID)
    {
    }

    void print() override
    {
        cout << "Araba Kaydi" << endl
            << "Marka  : " << arabaIsim << endl
            << "Model  : " << arabaID << endl
            << endl;
    }

    unique_ptr<Kayit> clone() override
    {
        return make_unique<ArabaKayit>(*this);
    }
};

class BisikledKayit : public Kayit
{
private:
    string bisikletIsim;
    int bisikletID;

public:
    BisikledKayit(string bisikletIsim, int ID) : bisikletIsim(bisikletIsim), bisikletID(ID)
    {
    }

    void print() override
    {
        cout << "Bisiklet Kaydi" << endl
            << "Marka  : " << bisikletIsim << endl
            << "Model  : " << bisikletID << endl
            << endl;
    }

    unique_ptr<Kayit> clone() override
    {
        return make_unique<BisikledKayit>(*this);
    }
};

class InsanKayit : public Kayit
{
private:
    string insanIsim;
    int yas;

public:
    InsanKayit(string insanIsim, int yas) : insanIsim(insanIsim), yas(yas)
    {
    }

    void print() override
    {
        cout << "Insan Kaydi" << endl
            << "Name : " << insanIsim << endl
            << "Age  : " << yas << endl
            << endl;
    }

    unique_ptr<Kayit> clone() override
    {
        return make_unique<InsanKayit>(*this);
    }
};

/* 
    Anlamlı bir kullanım için "KayitTipi" oluşturuyoruz.
*/
enum KayitTipi
{
    ARABA,
    BISIKLET,
    INSAN
};

/* 
    Bu kısımda ise kaydımızı oluşturuyoruz.
*/
class KayitFactory
{
private:
    unordered_map<KayitTipi, unique_ptr<Kayit>, hash<int>> kayit;

public:
    KayitFactory()
    {
        kayit[ARABA] = make_unique<ArabaKayit>("Ford Focus", 94);
        kayit[BISIKLET] = make_unique<BisikledKayit>("Yamaha", 2525);
        kayit[INSAN] = make_unique<InsanKayit>("Salih AYDOGAN", 25);
    }

    unique_ptr<Kayit> kayitOlustur(KayitTipi recordType)
    {
        return kayit[recordType]->clone();
    }
};

/* Kullanımda ise ilk önce "KayitFactory" nesnesi oluşturuyoruz. ardıdnan oluşturduğımız nesne ile "kayitOlustur" methodunu kullanıp, ilgili PROTOTİBİMİZİ çağırmış oluyoruz. */
int main()
{
    KayitFactory kayitFactory;

    auto kayit = kayitFactory.kayitOlustur(ARABA);
    kayit->print();

    kayit = kayitFactory.kayitOlustur(BISIKLET);
    kayit->print();

    kayit = kayitFactory.kayitOlustur(INSAN);
    kayit->print();
}

/*
    "Prototype Pattern"  ile bir şablon kullanarak, oluşturulacak nesnelerin türünü belirlemiş olduk. İlgili nesne üzerinden aynı tipte başka bir nesneyi hızlıca üreterek, üretimi esnasında maliyetli olabilecek nesneleri(ki burada maliyetten kasıt parametreli constructer vs. olabilir) var olan nesne üzerinden new anahtar sözcüğünü kullanmadan bir şekilde oluşturulması sağlandı.
*/