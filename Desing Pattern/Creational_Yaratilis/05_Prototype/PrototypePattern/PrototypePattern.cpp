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

class Kayit
{
public:
    virtual ~Kayit() {}
    virtual void print() = 0;
    virtual unique_ptr<Kayit> clone() = 0;
};

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

enum KayitTipi
{
    ARABA,
    BISIKLET,
    INSAN
};

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
    "Prototype Pattern"  ile bir şablon kullanarak, oluşturulacak nesnelerin türünü belirlemiş olduk. 
*/