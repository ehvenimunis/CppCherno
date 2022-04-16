//============================================================================
// İsim        : 01_Singleton
// Yazan       : Mert AceL
// Version     : 1.0
// Copyright   : AceL
// Açıklama    : Singleton Giriş Örneği
//============================================================================
#include <iostream>
#include <string>

using namespace std;

class Mesaj
{
private:
  // INSTANCE değişkenini tanımlıyoruz
  static Mesaj *INSTANCE;
  string mesaj;

protected:
  // Constructor Methodumuz
  Mesaj()
  {
  }

  // c++ 11 ile gelen, constructor kopyalanmasını engellenyen yapı
  Mesaj(const Mesaj &) = delete;

  // Atama operatörü "=" derleyici tarafından
  // otomatik üretebilinen bir operatördür.
  // Bu da singleton için işlevini kaybetmeye sebep olabilir.
  // Bunuda tanımlamamız karşılaşılacak problemleri azaltır.
  Mesaj &operator=(const Mesaj &) = delete;

  // Güvenlik olarak Destructor özel yapmaktır. Bu önlem,
  // Singleton nesnesinin  istem dışı olarak silmesini engeller.
  ~Mesaj();

public:
  // Mesaj sınıfımızı kullanmak için oluşturduğumuz public türündeki method
  static Mesaj *getInstance()
  {
    // Eğer INSTANCE değeri 0 ise yani hiç bu sınıf çağırılmamışsa,
    // sınıfı oluşturuyoruz.
    if (INSTANCE == 0)
    {
      INSTANCE = new Mesaj();
    }
    // Eğer bu sınıf daha öncd oluşturulmuşsa, yani çağırılmışsa geriye
    // var olan "INSTANCE"yi döndürüyoruz
    return INSTANCE;
  }

  // mesaj değişkenine veri atamamıza yardımcı olan method
  void setMesaj(string mesaj)
  {
    this->mesaj = mesaj;
  }

  // mesaj değişkeninden veri almaya yarayan method
  string getMesaj()
  {
    return this->mesaj;
  }

  // mesaj değişken içeriğini yazmaya yarayan method
  void mesajYazir()
  {
    cout << "Mesajınız : " << getMesaj() << endl;
  }
};

// INSTANCE değerine ilk atama, sıfırlama işlemi yapan kısım
Mesaj *Mesaj::INSTANCE = 0;

int main()
{
  // 1. Kullanış Biçimi : Bir "Mesaj" sınıfından "m1" adında nesne yaratıp,
  // Mesaj sınıfının "Instance"sini içeri aktrıyoruz
  Mesaj *m1 = Mesaj::getInstance();
  m1->setMesaj("Test");
  m1->mesajYazir();

  // 2. Kullanış Biçimi : Hiç bir nesne yaratmadan direk kullanabiliyoruz.
  Mesaj::getInstance()->setMesaj("Merhaba");
  Mesaj::getInstance()->mesajYazir();

  // Burada da gösterilmek istenen, tekrar bir nesne yaratılmasına rağmen ve
  // setMesaj() fonksiyonunu kullanmamamıza rağmen, bir önceki hali oluyor.
  Mesaj *m2 = Mesaj::getInstance();
  m2->mesajYazir();

  return 0;
}
