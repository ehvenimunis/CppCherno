//============================================================================
// İsim        : 01_Chain_of_Responsibility
// Yazan       : Salih Aydoğan
// Version     : 1.0
// Copyright   : 
// Açıklama    : Chain of Responsibility
//============================================================================
#include <iostream>
#include <string>

using namespace std;

/*  Bu sınıf, içinde kendi tipinde bir nesne bulundurmakta. Bu nesne üzerinden işlemler gerçekleşecek. */
class TrafikKurallari
{
protected:
    TrafikKurallari* trafikKurallari;

public:
    TrafikKurallari()
    {
        trafikKurallari = NULL; /* Bu sınıf oluşturulnca yani **"constructor"**da, oluşturduğumuz nesneye "NULL" değerini atıyoruz. */
    }

    virtual ~TrafikKurallari() {} /* sanal bir "deconstructor" oluşturuyoruz. Bu oluşturduğumuz sınıfı silme işleminde kullanılmaktadır. */

    virtual void sorgula(int value) = 0; /*  Bu method, alt sınıfta hıza göre işlemler yapacak. "setKuralDegistir" methodu ise, başta belirtilen kuralları değiştirmeye yaramaktadır.*/

    void setKuralDegistir(TrafikKurallari* yolTipi)
    {
        trafikKurallari = yolTipi;
    }
};

class Yol : public TrafikKurallari /* "TrafikKurallari" sınıfında miras alan "Yol" sınıfını oluşturuyoruz. */
{
private:
    int hizLimiti;
    string yolTipi;

public:
    /*
    Her yol tipine göre hız limiti farklıdır. Bu sınıfın "constructor" methodunda yola ait tipi ve limiti alıyoruz. Burada "sorgula" isimde, "TrafikKurallari" sınıfından gelen bir method bulunmakta. Bu method, yapılan hıza göre, "Yol" sınıfı oluşurken belirlediği limitlere ile karşılaştırmasını sağlar. Karşılaştırma sonucuna görede ekrana belirli bilgiler verir.
    */
    Yol(string yolTipi, int hizLimiti)
    {
        this->hizLimiti = hizLimiti;
        this->yolTipi = yolTipi;
    }

    ~Yol() {}

    void sorgula(int yapilanHiz) override
    {
        if (yapilanHiz < hizLimiti)
        {
            cout << "--------------------------------------------------" << endl;
            cout << "Yol Tipi : " << yolTipi << endl
                << "Hız Limiti : " << hizLimiti << endl
                << "Yapılan Hız : " << yapilanHiz << endl
                << "Sonuç : Ceza Almadınız." << endl;
        }
        else if (trafikKurallari != NULL)
        {
            trafikKurallari->sorgula(yapilanHiz);
        }
        else
        {
            cout << "--------------------------------------------------" << endl;
            cout << "Dikkat !!! Hız Limit Aşımı" << endl
                << "Yol Tipi : " << yolTipi << endl
                << "Yapılan Hız " << yapilanHiz << endl
                << "Bu Yolda Limit : " << hizLimiti << endl
                << "Lütfen Limitte Kalınız." << endl;
        }
    }
};

/*
Bu sistematiği kullanmak için, "TrafikKurallari" tipinde ve "Yol" sınıfından nesneler oluşturmamız gerekmektedir. Ardından hız sorgulamaları gerçekleşecektir. Eğer "setKuralDegistir" methodu kullanılırsa, "()" içinde belirtilen, daha önceden tanımlanmış olan yol bilgilerine göre, yol tipi ve hızına göre işlem gerçekleşecektir.
*/
int main()
{
    TrafikKurallari* ulke1 = new Yol("Tek Şerit", 100);
    TrafikKurallari* ulke2 = new Yol("Çift Şerit", 120);
    TrafikKurallari* ulke3 = new Yol("Otoban", 150);

    ulke1->sorgula(80);
    ulke1->sorgula(115);

    ulke1->setKuralDegistir(ulke2);
    ulke1->sorgula(90);
    ulke1->sorgula(115);

    ulke2->sorgula(85);
    ulke2->sorgula(130);
    ulke2->setKuralDegistir(ulke3);
    ulke2->sorgula(140);

    delete ulke1;
    delete ulke2;
    delete ulke3;

    return 0;
}

/*

--------------------------------------------------
Yol Tipi : Tek Ìerit
H²z Limiti : 100
Yap²lan H²z : 80
Sonu : Ceza Almad²n²z.
--------------------------------------------------
Dikkat !!! H²z Limit A■²m²
Yol Tipi : Tek Ìerit
Yap²lan H²z 115
Bu Yolda Limit : 100
L³tfen Limitte Kal²n²z.
--------------------------------------------------
Yol Tipi : Tek Ìerit
H²z Limiti : 100
Yap²lan H²z : 90
Sonu : Ceza Almad²n²z.
--------------------------------------------------
Yol Tipi : Ãift Ìerit
H²z Limiti : 120
Yap²lan H²z : 115
Sonu : Ceza Almad²n²z.
--------------------------------------------------
Yol Tipi : Ãift Ìerit
H²z Limiti : 120
Yap²lan H²z : 85
Sonu : Ceza Almad²n²z.
--------------------------------------------------
Dikkat !!! H²z Limit A■²m²
Yol Tipi : Ãift Ìerit
Yap²lan H²z 130
Bu Yolda Limit : 120
L³tfen Limitte Kal²n²z.
--------------------------------------------------
Yol Tipi : Otoban
H²z Limiti : 150
Yap²lan H²z : 140
Sonu : Ceza Almad²n²z.

*/