# Command Pattern

**"Command Pattern"** bir isteği bir nesne olarak kapsüllemek için kullanılır. Böylece istemcileri farklı isteklere, sıraya veya kayıt isteklerine göre parametrelendirmenize ve geri alınamayan işlemleri desteklemenize izin verir. Command ( Komut ) tasarım deseni, bir isteği kendisi ile ilgili tüm bilgileri içeren bağımsız bir nesneye dönüştüren davranışsal bir tasarım desenidir. Bu dönüşüm, istekleri metot parametresi olarak göndermenize, işlenmelerini geciktirmenize ya da sıraya sokmanıza ve geri alınamaz işlemleri desteklemenize olanak verir.

## Uygulanabilirlik

#### İşlevler içeren nesneleri parametre olarak kullanmak istediğinizde Command desenini kullanabilirsiniz.

Command deseni spesifik bir metod çağrısını bağımsız bir nesneye dönüştürebilir. Bu değişiklik bir çok ilginç kullanımın kapısını açar. Command’leri metodlara parametre olarak gönderebilir, onları başka nesnelerin içerisinde saklayabilir ve bağlı command’leri çalışma esnasında değiştirebilirsiniz.

Örneğin bir düğmelerden oluşan bir GUI bileşeni oluşturduğunuzu ve kullanıcının bu düğmelerin işlevlerini değiştirebilmesini istediğinizi düşünün. Bu Command deseni için harika bir kullanım alanıdır.

#### İşlemleri sıralaya almak, zamanlamak veya uzaktan çalıştırabilmek için Command desenini kullanabilirsiniz.

Başka nesnelerde de olduğu gibi command nesnesi seriye dönüştürülebilir (serialize), bu da metine dönüştürülerek bir dosyaya ya da veri tabanına yazılmasına olanak verir. Böylece çalışmasına geciktirebilir veya zamanlayabilirsiniz. Bu yöntemle command’leri sıraya alabilir, loglayabilir veya ağ üzerinden komutlar gönderebilirsiniz.

#### Geri döndürülebilir işlemler oluşturmak istediğinizde command desenini kullanabilirsiniz.

Geri Al / Tekrar Uygula (Undo/Redo) için çeşitli yöntemler olsa da Command deseni bunlar arasında en popüler olanıdır.

İşlemleri geri almak için yapılan işlemlerin bir geçmişini tutmanız gerekir. Command geçmişi çalıştırılan tüm command nesneleri ve uygulamanın anlık durumunun yedeğini alan bir yoğındır.

Tabi bu metodun dezavantajları da var. İlk olarak, uygulamanın bazı bölümleri özel (private) olacağı için durumunu saklamak her zaman kolay olmaz. Bu sorun Memento deseni ile çözülebilir. İkinci sorun ise durum yedeklerinin çok fazla hafıza (RAM) işgal ediyor olmasıdır. Bu nedenle bazen alternatif bir çözüme gidebilir, önceki duruma dönmek yerine, mevcut işlemin tersini yapabilirsiniz. Tersine işlem yapmanın da bir bedeli var, o da uygulamanın zor, hatta bazen imkansız olması.

## Command Pattern Kullanım Adımları

* İlk olarak soyut bir sınıf oluşturuyoruz. Bu sınıfa **"Komut"** ismini verdik. Bu sınıfın  **"calistir"** isminde bir methodu bulunmakta.

```cpp
class Komut
{
public:
  virtual void calistir() = 0;
};
```

* Ardından işlem görecek sınıfımızı hazırlıyoruz. Bu sınıf ismine **"Isik"** ismini verdik. Bu sınıf, ışığı açma ve kapama işlemi gerçekleştiriyor.

```cpp
class Isik
{
public:
  Isik() {}

  void ac()
  {
    cout << "Işık Açıldı..." << endl;
  }

  void kapat()
  {
    cout << "Işık Kapandı..." << endl;
  }
};
```

* Sonraki adım olarak, **Komut"** sınıfından komutlar üretiyoruz. Projemizde **"AcKomut"** ve **"KapatKomut"** olarak 2 komut bulunmakta.

```cpp
class AcKomut : public Komut
{
private:
  Isik &isik;

public:
  AcKomut(Isik &isik) : isik(isik)
  {
  }

  virtual void calistir()
  {
    isik.ac();
  }
};


class KapatKomut : public Komut
{
private:
  Isik &isik;

public:
  KapatKomut(Isik &isik) : isik(isik)
  {
  }
  virtual void calistir() override
  {
    isik.kapat();
  }
};
```

* Son adım olarak **"Degistir"** sınıfını tanımlıyoruz. Bu sınıf, bir ışığın açma ve kapatma durumlarını kontrol etmektedir.

```cpp
class Degistir
{
  private:
  Komut &acKomut;
  Komut &kapatKomut;

public:
  Degistir(Komut &acKomut, Komut &kapatKomut)
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
```

* Şimdi yazdığımız sınıfların kontrolünü yapalım. ilk olarak **"Isik"** sınıfından bir nesne üretiyoruz. Ardından **"Komut"** sınıfından türetilen, **"AcKomut"** ve **"KapatKomut"** sınıflarıdnan nesneler üretiyoruz.   **"Isik"** sınıfından ürettiğimiz nesneleride komutlara veriyoruz.  En sonra **"Degistir"** sınıfından nesne üret,yoruz ve komut nesnelerinide parametre olarak veriyoruz. Artık kolay bir şekilde komutumuzu kullanabiliriz. **"ac"**, **"kapat"** fonksiyonları sayesinde, ışık açma - kapatma işlemlerini gerçekleştiriyoruz.

```cpp
int main()
{
  Isik lamba;
  AcKomut degistirAc(lamba);
  KapatKomut degistirKapat(lamba);

  Degistir s(degistirAc, degistirKapat);
  s.ac();
  s.kapat();
}
```