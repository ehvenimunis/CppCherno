// Composite.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//
#include <vector>
#include <iostream>
#include <memory>       // unique_ptr için başlık dosyası
#include <algorithm>
using namespace std;

/* İlk önce "Grafik" isminde ana soyut sınıfımızı oluşturuyoruz. */
class Grafik
{
public:
    virtual void yazdir() const = 0;
};

/*Ardından bu sınıftan türeyecek olan "Elips", "Ucgen", "Elips", türlerinde nesneler oluşturuyoruz.*/
class Elips : public Grafik
{
public:
    void yazdir() const override
    {
        cout << "Elips \n";
    }
};

class Kare : public Grafik
{
public:
    void yazdir() const override
    {
        cout << "Kare \n";
    }
};

class Ucgen : public Grafik
{
public:
    void yazdir() const override
    {
        cout << "Ucgen \n";
    }
};
/* Daha önce oluşturuduğumuz sınıfları tek tek kullanılabileceği gibi, "CompositeGrafik" olduğu gibi toplu işlerde yapılabilmektedir. Burada "ekle" methodu sayesinde, "Grafik" sınıf türündeki nesneleri ortak olarak kullanabilmekteyiz. */
class CompositeGrafik : public Grafik
{
private:
    vector<Grafik*> grafikListesi;

public:
    void yazdir() const override
    {
        for (Grafik* grafik : grafikListesi)
        {
            grafik->yazdir();
        }
    }

    void ekle(Grafik* grafik)
    {
        grafikListesi.push_back(grafik);
    }
};

int main()
{
    // Initialize four ellipses
    const unique_ptr<Elips> elips1(new Elips());  // Hayata Elips dinamik nesnesi getiriyoruz
    /* Bir unique_ptr nesnesi gösterdiği kaynağın (örneğin dinamik ömürlü bir nesnenin) tek sahibi durumundadır. 
    unique_ptr nesnesinin hayatı sonlandığında yani bir unique_ptr nesnesi için sonlandırıcı işlevi çağrıldığında 
    sahip olunan kaynak da sonlandırılır.*/
    const unique_ptr<Elips> elips2(new Elips());
    const unique_ptr<Kare> kare(new Kare());
    const unique_ptr<Ucgen> ucgen(new Ucgen());

    // Initialize three composite graphics
    const unique_ptr<CompositeGrafik> graphic1(new CompositeGrafik());
    const unique_ptr<CompositeGrafik> graphic2(new CompositeGrafik());
    const unique_ptr<CompositeGrafik> graphic3(new CompositeGrafik());

    // Composes the graphics
    graphic2->ekle(elips1.get());
    graphic2->ekle(elips2.get());
    graphic2->ekle(ucgen.get());

    graphic3->ekle(kare.get());

    graphic1->ekle(graphic2.get());
    graphic1->ekle(graphic3.get());

    // Prints the complete graphic (four times the string "Ellipse")
    graphic1->yazdir();

    cout << endl;
    graphic2->yazdir();
    return 0;
}

/*
    Elips
    Elips
    Ucgen
    Kare

    Elips
    Elips
    Ucgen
*/