//============================================================================
// İsim        : Singleton
// Yazan       : Muhammed Salih Aydoğan
// Version     : 1.0
// Copyright   : 
// Açıklama    : Singleton Pattern with thread
//============================================================================

#include <iostream>
#include <string>
#include <mutex>

using namespace std;

mutex mtx;

class Mesaj
{
private:
    // INSTANCE değişkenini tanımlıyoruz
    static Mesaj* INSTANCE;
    string mesaj;

protected:
    // Constructor Methodumuz
    Mesaj()
    {
    }

    // c++ 11 ile gelen, constructor kopyalanmasını engellenyen yapı
    Mesaj(const Mesaj&) = delete;

    // Atama operatörü "=" derleyici tarafından
    // otomatik üretebilinen bir operatördür.
    // Bu da singleton için işlevini kaybetmeye sebep olabilir.
    // Bunuda tanımlamamız karşılaşılacak problemleri azaltır.
    Mesaj& operator=(const Mesaj&) = delete;

    // Güvenlik olarak Destructor özel yapmaktır. Bu önlem,
    // Singleton nesnesinin  istem dışı olarak silmesini engeller.
    ~Mesaj();

public:
    static Mesaj* getInstance()
    {
        // Eğer INSTANCE değeri 0 ise yani hiç bu sınıf çağırılmamışsa,
        // sınıfı oluşturuyoruz.
        // Eğer çift kontrollü olursa daha güvenli olduğu gözlemlenmiştir http://www.drdobbs.com/cpp/c-and-the-perils-of-double-checked-locki/184405726
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
        cout << "Your Messsage : " << getMesaj() << endl;
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

// INSTANCE değerine ilk atama, sıfırlama işlemi yapan kısım
Mesaj* Mesaj::INSTANCE = 0;

int main()
{
    // 1. Kullanış Biçimi
    Mesaj* m1 = Mesaj::getInstance();
    m1->setMesaj("Test");
    m1->mesajYazir();

    // 2. Kullanış Biçimi
    Mesaj::getInstance()->setMesaj("Hello");
    Mesaj::getInstance()->mesajYazir();

    // Burada da gösterilmek istenen, tekrar bir nesne yaratılmasına rağmen ve
    // setMesaj() fonksiyonunu kullanmamamıza rağmen, bir önceki hali oluyor.
    Mesaj* m2 = Mesaj::getInstance();
    m2->mesajYazir();

    // Burada da gösterilmek istenen, tekrar bir nesne yaratılmasına rağmen ve
    // setMesaj() fonksiyonunu kullanmamamıza rağmen, bir önceki hali oluyor.
    Mesaj* m3 = Mesaj::getInstance();
    m3->mesajYazir();

    return 0;
}