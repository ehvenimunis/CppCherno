//============================================================================
// İsim        : 02_Command
// Yazan       : Salih Aydoğan
// Version     : 1.0
// Copyright   : MSA
// Açıklama    : Command Pattern
//============================================================================
#include <iostream>

using namespace std;

/*soyut bir sınıf oluşturuyoruz.*/
class Komut
{
public:
    virtual void calistir() = 0;
};

/* işlem görecek sınıfımızı hazırlıyoruz. Bu sınıf ismine "Isik" ismini verdik. Bu sınıf, ışığı açma ve kapama işlemi gerçekleştiriyor.*/
class Isik
{
public:
    Isik() {}

    void ac()
    {
        cout << "Light Opened..." << endl;
    }

    void kapat()
    {
        cout << "Light Closed..." << endl;
    }
};

/*"Komut" sınıfından komutlar üretiyoruz. Projemizde "AcKomut" ve "KapatKomut" olarak 2 komut bulunmakta.*/
class AcKomut : public Komut
{
private:
    Isik& isik;

public:
    AcKomut(Isik& isik) : isik(isik)
    {
    }

    virtual void calistir() override
    {
        isik.ac();
    }
};


class KapatKomut : public Komut
{
private:
    Isik& isik;

public:
    KapatKomut(Isik& isik) : isik(isik)
    {
    }
    virtual void calistir() override
    {
        isik.kapat();
    }
};

/*Son adım olarak "Degistir" sınıfını tanımlıyoruz. Bu sınıf, bir ışığın açma ve kapatma durumlarını kontrol etmektedir.*/
class Degistir
{
private:
    Komut& acKomut;
    Komut& kapatKomut;

public:
    Degistir(Komut& acKomut, Komut& kapatKomut)
        : acKomut(acKomut), kapatKomut(kapatKomut)
    {
    }

    void ac()
    {
        acKomut.calistir();
    }

    void kapat()
    {
        kapatKomut.calistir();
    }
};

int main()
{
    /*
    ilk olarak "Isik" sınıfından bir nesne üretiyoruz. Ardından "Komut" sınıfından türetilen, "AcKomut" ve "KapatKomut" sınıflarıdnan nesneler üretiyoruz. "Isik" sınıfından ürettiğimiz nesneleride komutlara veriyoruz. En sonra "Degistir" sınıfından nesne üret,yoruz ve komut nesnelerinide parametre olarak veriyoruz. Artık kolay bir şekilde komutumuzu kullanabiliriz. "ac", "kapat" fonksiyonları sayesinde, ışık açma - kapatma işlemlerini gerçekleştiriyoruz.
    */
    Isik lamba;
    AcKomut degistirAc(lamba);
    KapatKomut degistirKapat(lamba);

    Degistir s(degistirAc, degistirKapat);
    s.ac();
    s.kapat();
}

/*

    Light Opened...
    Light Closed...

*/