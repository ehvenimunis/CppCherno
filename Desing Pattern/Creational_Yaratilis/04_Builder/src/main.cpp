//============================================================================
// İsim        : 04_Builder
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
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
    void setAnakart(const string &anakart)
    {
        this->anakart = anakart;
    }
    void setRam(const string &ram)
    {
        this->ram = ram;
    }
    void setEkranKarti(const string &ekranKarti)
    {
        this->ekranKarti = ekranKarti;
    }

    void setSegment(const string &segment)
    {
        this->segment = segment;
    }

    void kur() const
    {
        cout << segment << " Bilgisayar Özellikleri - Anakart " << anakart << ", Ram Bellek : " << ram << ", Ekran Kartı : "
             << ekranKarti << " - Kurulum Tamamlandı" << endl;
    }
};

class BilgisayarBuilder
{
  protected:
    unique_ptr<Bilgisayar> bilgisayar;

  public:
    virtual ~BilgisayarBuilder(){};

    Bilgisayar *getBilgisayar()
    {
        return bilgisayar.release();
    }
    void yeniBilgisayarOlustur()
    {
        bilgisayar = make_unique<Bilgisayar>();
    }
    virtual void buildAnakart() = 0;
    virtual void buildRam() = 0;
    virtual void buildEkrankarti() = 0;
    virtual void buildSegment() = 0;
};

//----------------------------------------------------------------

class OrtaSegmetBilgisayarBuilder : public BilgisayarBuilder
{
  public:
    virtual ~OrtaSegmetBilgisayarBuilder(){};

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
    virtual ~UstSegmetBilgisayarBuilder(){};

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

//----------------------------------------------------------------
class Build
{
  private:
    BilgisayarBuilder *bilgisayarBuilder;

  public:
    void bilgisayarSec(BilgisayarBuilder *pb)
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