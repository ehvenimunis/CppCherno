#include <iostream>
#include <string>
#include <mutex>

using namespace std;

mutex mtx;

class Mesaj
{
private:
    // INSTANCE de�i�kenini tan�ml�yoruz
    static Mesaj* INSTANCE;
    string mesaj;

protected:
    // Constructor Methodumuz
    Mesaj()
    {
    }

    // c++ 11 ile gelen, constructor kopyalanmas�n� engellenyen yap�
    Mesaj(const Mesaj&) = delete;

    // Atama operat�r� "=" derleyici taraf�ndan
    // otomatik �retebilinen bir operat�rd�r.
    // Bu da singleton i�in i�levini kaybetmeye sebep olabilir.
    // Bunuda tan�mlamam�z kar��la��lacak problemleri azalt�r.
    Mesaj& operator=(const Mesaj&) = delete;

    // G�venlik olarak Destructor �zel yapmakt�r. Bu �nlem,
    // Singleton nesnesinin  istem d��� olarak silmesini engeller.
    ~Mesaj();

public:
    static Mesaj* getInstance()
    {
        // E�er �ift kontroll� olursa daha g�venli oldu�u g�zlemlenmi�tir http://www.drdobbs.com/cpp/c-and-the-perils-of-double-checked-locki/184405726
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
        cout << "Mesaj�n�z : " << getMesaj() << endl;
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

// INSTANCE de�erine ilk atama, s�f�rlama i�lemi yapan k�s�m
Mesaj* Mesaj::INSTANCE = 0;

int main()
{
    // 1. Kullan�� Bi�imi
    Mesaj* m1 = Mesaj::getInstance();
    m1->setMesaj("Test");
    m1->mesajYazir();

    // 2. Kullan�� Bi�imi
    Mesaj::getInstance()->setMesaj("Merhaba");
    Mesaj::getInstance()->mesajYazir();

    return 0;
}