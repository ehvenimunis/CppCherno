//============================================================================
// İsim        : BuilderPattern
// Yazan       : Muhammed Salih Aydoğan
// Version     : 1.0
// Copyright   : 
// Açıklama    : Builder Pattern
//============================================================================
#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Bilgisayar
{
private:
    string anakart;
    string ram;
    string ekranKarti;
    string segment;

public:
    void setAnakart(const string& anakart)
    {
        this->anakart = anakart;
    }
    void setRam(const string& ram)
    {
        this->ram = ram;
    }
    void setEkranKarti(const string& ekranKarti)
    {
        this->ekranKarti = ekranKarti;
    }

    void setSegment(const string& segment)
    {
        this->segment = segment;
    }

    void kur() const
    {
        cout << segment << " Bilgisayar Özellikleri - Anakart " << anakart << ", Ram Bellek : " << ram << ", Ekran Kartı : "
            << ekranKarti << " - Kurulum Tamamlandı" << endl;
    }
};

/*  
    Ana sınıfımızın "Builder" ını oluşturuyoruz. Bu sınıf soyut bir sınıftır. "buildAnakart", "buildRam", "buildEkrankarti", "buildSegment" methodları bulunmaktadır.
*/
class BilgisayarBuilder 
{
protected:
    /*
        Pointer ile çalıştığımızda ve "new" ile yeni sınıflar oluşturduğumuzda, "RAM" bellekte yer kaplayacaktır
        Bunları işlemlerimiz bitince silmemiz gerekmektedir.
        "unique_ptr" bu işlemi bizim için, efektif bir biçimde yerine getirmektedir.
    */
    unique_ptr<Bilgisayar> bilgisayar; 

public:
    virtual ~BilgisayarBuilder() {};

    Bilgisayar* getBilgisayar() //  Bu method, geriye oluşturduğumuz "Bilgisayar" nesnesini döndürür. 
    {
        return bilgisayar.release();
    }
    void yeniBilgisayarOlustur() // "Bilgisayar" türünden bir sınıf oluşturup, "bilgisayar" değişkenine atar
    {
        bilgisayar = make_unique<Bilgisayar>();
    }
    virtual void buildAnakart() = 0;
    virtual void buildRam() = 0;
    virtual void buildEkrankarti() = 0;
    virtual void buildSegment() = 0;
};

/*
* "BilgisayarBuilder" dan türetilen, spesifik alt sınıfları oluşturuyoruz. Bu sınıfların amacı, "BilgisayarBuilder" da bulunan ve istenen "buildAnakart", "buildRam", "buildEkrankarti",
* "buildSegment" methodlarını anlamlandırmak. Verileri atamak.
*/
class OrtaSegmetBilgisayarBuilder : public BilgisayarBuilder
{
public:
    virtual ~OrtaSegmetBilgisayarBuilder() {};

    void buildAnakart() override
    {
        bilgisayar->setAnakart("Asus");
    }

    void buildRam() override
    {
        bilgisayar->setRam("8 GB");
    }

    void buildEkrankarti() override
    {
        bilgisayar->setEkranKarti("2 GB AMD");
    }

    void buildSegment() override
    {
        bilgisayar->setSegment("Orta Segmet");
    }
};

class UstSegmetBilgisayarBuilder : public BilgisayarBuilder
{
public:
    virtual ~UstSegmetBilgisayarBuilder() {};

    void buildAnakart() override
    {
        bilgisayar->setAnakart("Gigabyte");
    }

    void buildRam() override
    {
        bilgisayar->setRam("16 GB");
    }

    void buildEkrankarti() override
    {
        bilgisayar->setEkranKarti("8 GB NVDIA");
    }

    void buildSegment() override
    {
        bilgisayar->setSegment("Üst Segmet");
    }
};

class Build
{
private:
    BilgisayarBuilder* bilgisayarBuilder;

public:
    void bilgisayarSec(BilgisayarBuilder* pb) // Bu method, kullanıcıdan "BilgisayarBuilder" türünde değişken almakta.
    {
        bilgisayarBuilder = pb;
        bilgisayarBuilder->yeniBilgisayarOlustur();
        bilgisayarBuilder->buildAnakart();
        bilgisayarBuilder->buildEkrankarti();
        bilgisayarBuilder->buildRam();
        bilgisayarBuilder->buildSegment();
    }

    void bilgisayarKur()
    {
        bilgisayarBuilder->getBilgisayar()->kur();
    }
};

int main()
{
    Build build;
    OrtaSegmetBilgisayarBuilder ortaSegment;
    UstSegmetBilgisayarBuilder ustSegment;

    build.bilgisayarSec(&ortaSegment);
    build.bilgisayarKur();

    build.bilgisayarSec(&ustSegment);
    build.bilgisayarKur();
}

/*
* Aynı oluşturma işlemi ile farklı nesneler oluşturduk.
* Karmaşık bir obje oluşturduk fakat karmaşık bir kurucu üyeye veya argümanlara ihtiyaç duymadık.
*/