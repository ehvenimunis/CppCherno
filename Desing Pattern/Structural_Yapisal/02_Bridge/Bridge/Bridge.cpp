#include <iostream>

using namespace std;

/* Uygulatıcı
    İlk olarak, "CizimAPISablon" isminde bir soyut sınıf tanımlıyoruz.
*/
class CizimAPISablon
{
public:
    virtual void cemberCiz(double x, double y, double yaricap) = 0;
};

/* Somut Uygulatıcı A
    Ardından bu sınıftan miras alan "CizimAPI1", "CizimAPI2" sınıflarını oluşturuyoruz. Bu sınıflar, "cemberCiz" methodunu kendine göre yorumlamaya olanak sağlamaktadır.
*/
class CizimAPI1 : public CizimAPISablon
{
public:
    void cemberCiz(double x, double y, double yaricap) override
    {
        cout << "CizimAPI1 Verileri x:  " << x << " y :" << y << " yarı çap : " << yaricap << endl;
    }
};

/* Somut Uygulatıcı B*/
class CizimAPI2 : public CizimAPISablon
{
public:
    void cemberCiz(double x, double y, double yaricap) override
    {
        cout << "CizimAPI2 Verileri x:  " << x << " y :" << y << " yarı çap : " << yaricap << endl;
    }
};

/* Soyutlama 
    Ardından "Sekil" isminde soyut bir sınıf oluşturyoruz. Bu sınıf, "ciz" ve "boyutArttir" isminde iki methodu bulunmakta.
*/
class Sekil
{
public:
    virtual void ciz() = 0;
    virtual void boyutArttir(double boyutlandir) = 0;
};

/* Soyut İşleme
    Son olarak "Sekil" sınıfından türetilen "DaireSekil" için gerekli sınıfı hazırlıyoruz. Bu sınıf constructor ile verileri almakta. Ardından soyut sınıftan gelen methodlar ile işlemlerimizi gerçekleştiriyoruz.
*/
class DaireSekil : public Sekil
{
private:
    double m_x, m_y, yaricap;
    CizimAPISablon* cizimAPI;

public:
    DaireSekil(double x, double y, double yaricap, CizimAPISablon* cizimAPI) : m_x(x), m_y(y), yaricap(yaricap), cizimAPI(cizimAPI)
    {
    }
    void ciz() override
    {
        cizimAPI->cemberCiz(m_x, m_y, yaricap);
    }
    void boyutArttir(double boyutlandir) override
    {
        yaricap *= boyutlandir;
    }
};

/* 
    Kullanım oldukça kolaydır. İlk olarak "DaireSekil" sınıfından nesne üretiyoruz. Nesne üretirken "x", "y", "yarıçap" ve "CizimAPI" türünde nesne veriyoruz. Ardından "boyutArttir" ve "ciz" methodlarını, verdiğimiz ""CizimAPI" türünde işlemler etabi tutmuş oluyoruz.
*/
int main()
{
    DaireSekil daire1(1, 2, 3, new CizimAPI1());
    DaireSekil daire2(5, 7, 11, new CizimAPI2());
    daire1.boyutArttir(2.5);
    daire2.boyutArttir(2.5);
    daire1.ciz();
    daire2.ciz();
    return 0;
}


/*
    CizimAPI1 Verileri x:  1 y :2 yar² ap : 7.5
    CizimAPI2 Verileri x:  5 y :7 yar² ap : 27.5
*/