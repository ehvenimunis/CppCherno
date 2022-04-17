#include <iostream>
#include <string>
#include <mutex>

using namespace std;

mutex mtx;

class Mesaj
{
private:
    // INSTANCE deðiþkenini tanýmlýyoruz
    static Mesaj* INSTANCE;
    string mesaj;

protected:
    // Constructor Methodumuz
    Mesaj()
    {
    }

    // c++ 11 ile gelen, constructor kopyalanmasýný engellenyen yapý
    Mesaj(const Mesaj&) = delete;

    // Atama operatörü "=" derleyici tarafýndan
    // otomatik üretebilinen bir operatördür.
    // Bu da singleton için iþlevini kaybetmeye sebep olabilir.
    // Bunuda tanýmlamamýz karþýlaþýlacak problemleri azaltýr.
    Mesaj& operator=(const Mesaj&) = delete;

    // Güvenlik olarak Destructor özel yapmaktýr. Bu önlem,
    // Singleton nesnesinin  istem dýþý olarak silmesini engeller.
    ~Mesaj();

public:
    static Mesaj* getInstance()
    {
        // Eðer çift kontrollü olursa daha güvenli olduðu gözlemlenmiþtir http://www.drdobbs.com/cpp/c-and-the-perils-of-double-checked-locki/184405726
        if (INSTANCE == 0)
        {
            mtx.lock();
            if (INSTANCE == 0)
            {
                INSTANCE = new Mesaj();
            }
            mtx.unlock();
        }
        return INSTANCE;
    }

    void mesajYazir()
    {
        cout << "Mesajýnýz : " << getMesaj() << endl;
    }

    void setMesaj(string mesaj)
    {
        this->mesaj = mesaj;
    }

    string getMesaj()
    {
        return this->mesaj;
    }
};

// INSTANCE deðerine ilk atama, sýfýrlama iþlemi yapan kýsým
Mesaj* Mesaj::INSTANCE = 0;

int main()
{
    // 1. Kullanýþ Biçimi
    Mesaj* m1 = Mesaj::getInstance();
    m1->setMesaj("Test");
    m1->mesajYazir();

    // 2. Kullanýþ Biçimi
    Mesaj::getInstance()->setMesaj("Merhaba");
    Mesaj::getInstance()->mesajYazir();

    return 0;
}