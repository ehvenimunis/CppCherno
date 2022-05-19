//============================================================================
// İsim        : Adapter
// Yazan       : Muhammed Salih Aydoğan
// Version     : 1.0
// Copyright   : 
// Açıklama    : Adapter Pattern ( Bir sınıfın arayüzünü istemcinin beklediği arayüze çevirmeye yarar.)
//============================================================================
#include <iostream>
using namespace std;

/*
    İlk önce soyut bir sınıf oluşturuyoruz. Sınıfımıza "Daire" ismini verdik. Bu sınıfın "ciz" adında bir methodu bulunmakta.
*/
class Daire
{
public:
    virtual void ciz() = 0;
};

/*
    Ardından "StandardDaire" isminde bir sınıf oluşturuyoruz. Bu sınıf, daire bilgilerini almaktadır. 
*/
class StandardDaire
{
private:
    double yariCap;

public:
    StandardDaire(double yariCap)
    {
        this->yariCap = yariCap;
        cout << "StandardDaire:  Yarat. Yarı Çapı = " << yariCap << endl;
    }
    void cizim()
    {
        cout << "StandardDaire:  Yarı Çapı. " << yariCap << endl;
    }
};

/*
    Ardından "DaireAdapter" isminde bir sınıf oluşturuyoruz. Bu sınıf, "Daire" ve "StandardDaire" sınıfından miras almakta. Bu dairenin içinde constructor olarak dairenin çap bilgisini almakta. Bu bilgiyi, "StandardDaire" sınıfına göndermekte. Ardından "ciz" methodu ile, "cizim" sınıfını çalıştırmakta.
 */
class DaireAdapter : public Daire, private StandardDaire //Adapter Class
{
public:
    DaireAdapter(double cap)
        : StandardDaire(cap / 2)
    {
        cout << "DaireAdapter: Yarat. Çapı = " << cap << endl;
    }
    virtual void ciz() override
    {
        cout << "DaireAdapter: Çiz." << endl;
        cizim();
    }
};

int main()
{
    Daire* c = new DaireAdapter(18);
    c->ciz();

    delete[] c;
}

/*

    StandardDaire:  Yarat. Yar² Ãap² = 9
    DaireAdapter: Yarat. Ãap² = 18
    DaireAdapter: Ãiz.
    StandardDaire:  Yar² Ãap². 9

*/