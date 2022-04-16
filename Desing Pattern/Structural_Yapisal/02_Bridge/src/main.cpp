//============================================================================
// İsim        : 02_Bridge
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Bridge Pattern
//============================================================================
#include <iostream>

using namespace std;

/* Uygulatıcı*/
class CizimAPISablon
{
  public:
    virtual void cemberCiz(double x, double y, double yaricap) = 0;
};

/* Somut Uygulatıcı A*/
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

/* Soyutlama*/
class Sekil
{
  public:
    virtual void ciz() = 0;
    virtual void boyutArttir(double boyutlandir) = 0;
};

/* Soyut İşleme*/
class DaireSekil : public Sekil
{
  private:
    double m_x, m_y, yaricap;
    CizimAPISablon *cizimAPI;

  public:
    DaireSekil(double x, double y, double yaricap, CizimAPISablon *cizimAPI) : m_x(x), m_y(y), yaricap(yaricap), cizimAPI(cizimAPI)
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
