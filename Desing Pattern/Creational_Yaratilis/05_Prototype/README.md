# Prototype Pattern
**"Prototype Pattern"**, bir şablon kullanarak, oluşturulacak nesnelerin türünü belirtir.Prototype tasarım deseni, mevcut nesnelerin prototiplerinin oluşturulmasını yani nesnelerin kopyalarını elde etmeyi sağlayan bir tasarım desenidir. Prototip deseninin tasarlanmasının asıl sebebi, ilgili nesne üzerinden aynı tipte başka bir nesneyi hızlıca üretebilmektir. Haliyle üretimi esnasında maliyetli olabilecek nesneleri(ki burada maliyetten kasıt parametreli constructer vs. olabilir) var olan nesne üzerinden new anahtar sözcüğünü kullanmadan bir şekilde oluşturulmasını sağlayabilmektedir.

## PrototypeBuilder Pattern Kullanım Adımları

* İlk önce soyut bir sınıf oluşturuyoruz. Bu sınıf bizim temel prototip sınıfımız.

```cpp
class Kayit
{
  public:
    virtual ~Kayit() {}
    virtual void print() = 0;
    virtual unique_ptr<Kayit> clone() = 0;
};
```

* Oluşturduğumuz soyut sınıftan  somut prototiplerimizi oluşturuyoruz.

```cpp
class ArabaKayit : public Kayit
{
  private:
    string arabaIsim;
    int arabaID;

  public:
    ArabaKayit(string arabaIsim, int ID) : arabaIsim(arabaIsim), arabaID(ID)
    {
    }

    void print() override
    {
        cout << "Araba Kaydı" << endl
             << "Marka  : " << arabaIsim << endl
             << "Model  : " << arabaID << endl
             << endl;
    }

    unique_ptr<Kayit> clone() override
    {
        return make_unique<ArabaKayit>(*this);
    }
};

class BisikledKayit : public Kayit
{
  private:
    string bisikletIsim;
    int bisikletID;

  public:
    BisikledKayit(string bisikletIsim, int ID) : bisikletIsim(bisikletIsim), bisikletID(ID)
    {
    }

    void print() override
    {
        cout << "Bisiklet Kaydı" << endl
             << "Marka  : " << bisikletIsim << endl
             << "Model  : " << bisikletID << endl
             << endl;
    }

    unique_ptr<Kayit> clone() override
    {
        return make_unique<BisikledKayit>(*this);
    }
};

class InsanKayit : public Kayit
{
  private:
    string insanIsim;
    int yas;

  public:
    InsanKayit(string insanIsim, int yas) : insanIsim(insanIsim), yas(yas)
    {
    }

    void print() override
    {
        cout << "İnsan Kaydı" << endl
             << "İsim : " << insanIsim << endl
             << "Yaş  : " << yas << endl
             << endl;
    }

    unique_ptr<Kayit> clone() override
    {
        return make_unique<InsanKayit>(*this);
    }
};
```

* Anlamlı bir kullanım için **"KayitTipi"** oluşturuyoruz.

 ```cpp
enum KayitTipi
{
    ARABA,
    BISIKLET,
    INSAN
};
 ```

 * Bu kısımda ise kaydımızı oluşturuyoruz.

 ```cpp
class KayitFactory
{
  private:
    unordered_map<KayitTipi, unique_ptr<Kayit>, hash<int>> kayit;

  public:
    KayitFactory()
    {
        kayit[ARABA] = make_unique<ArabaKayit>("Tofaş Şahin", 94);
        kayit[BISIKLET] = make_unique<BisikledKayit>("Yammaha", 2525);
        kayit[INSAN] = make_unique<InsanKayit>("Salih Aydoğan", 25);
    }

    unique_ptr<Kayit> kayitOlustur(KayitTipi recordType)
    {
        return kayit[recordType]->clone();
    }
};
 ```

 * Kullanımda ise ilk önce **"KayitFactory"** nesnesi oluşturuyoruz. Ardından oluşturduğımız nesne ile **"kayitOlustur"** methodunu kullanıp, ilgili prototibimizi çağırmış oluyoruz.

 ```cpp
int main()
{
    KayitFactory kayitFactory;

    auto kayit = kayitFactory.kayitOlustur(ARABA);
    kayit->print();

    kayit = kayitFactory.kayitOlustur(BISIKLET);
    kayit->print();

    kayit = kayitFactory.kayitOlustur(INSAN);
    kayit->print();
}
 ```
