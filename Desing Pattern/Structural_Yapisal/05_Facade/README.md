# Facade Design Pattern

**"Facade Pattern"** pek çok sınıftan oluşan karmaşık bir sistemin karmaşıklığını saklamak ve istemci daha basit ve kolay kullanılabilir bir arayüz sunmak için kullanılır. Yapısal bir örüntüdür. Basitçe bu örüntü sisteme bir arayüz ekler ve sistemin karmaşıklığını giderir. 
Bir alt sistemin parçalarını oluşturan classları istemciden soyutlayarak kullanımı daha da kolaylaştırmak için tasarlanmış tasarım kalıbıdır. Mimarisel açıdan ise, karmaşık ve detaylı bir sistemi organize eden ve bir bütün olarak clientlara(istemcilere) sunan yapıdır. Anlayacağınız, karmaşık ve detaylı olarak nitelendirdiğimiz bu sistemi bir alt sistem olarak varsayarsak eğer bu sistemi kullanacak clientlara daha basit bir arayüz sağlamak ve alt sistemleri bu arayüze organize bir şekilde dahil etmek ve bu alt sistemlerin sağlıklı çalışabilmesi için bu arayüz çatısı altında işin algoritmasına uygun işlev sergilemek istersek Facade Design Pattern’i kullanmaktayız.
Burada bilmeniz gereken durum, alt sistem içerisinde bulunan sınıfların birbirlerinden bağımsız olmasıdır. Ayriyetten Facade sınıfından da bağımsız bir şekilde çalışabilmektedirler.
Facade bizim classlarımızı içermek zorundadır ve operasyonu yaparken onlara ait fonksiyonellikleri kullanması gerekli.

## Facade Pattern Kullanım Adımları

* İlk adım olarak yapılacak işlemleri, operasyonları tanımlıyoruz. Biz projemizde **"Alarm"**, **"Elektrik"**, **"Tv"** işlemleri tanımladık.

```cpp
class Alarm
{
  public:
    void alarmAc()
    {
        cout << "Alarm Açıldı. Eviniz güvende..." << endl;
    }

    void alarmKapat()
    {
        cout << "Alarm Kapatıldı..." << endl;
    }
};

class Elektrik
{
  public:
    void elektrikAc()
    {
        cout << "Elektrik Açık..." << endl;
    }

    void elektrikKapat()
    {
        cout << "Elektrik Kapalı..." << endl;
    }
};

class Tv
{
  public:
    void tvAc()
    {
        cout << "Tv Açık..." << endl;
    }

    void tvKapat()
    {
        cout << "TV Kapalı..." << endl;
    }
};

```

* Ardından **"EvFacade"** isminde bir sınıf oluşturduk. Bu sınıf içinde oluşturduğumuz **"Alarm"**, **"Elektrik"**, **"Tv"** sınıflarından nesneler yarattık. Bu sınıfımızda iki fonksiyonumuz bulunmakta. İlki **"evdenDisariCikinca"** methodu, ilk belirlediğimiz sınıflardan, evden çıkınca yapılacak olan işlemleri tanımlamakta. Diğeri **"eveDonunce"** methodu eve geri dönünce yapıalcak olan işlemleri barındırmaktadır.

```cpp
class EvFacade
{
    Alarm alarm;
    Elektrik elektrik;
    Tv tv;

  public:
    EvFacade() {}

    void evdenDisariCikinca()
    {
        elektrik.elektrikKapat();
        tv.tvKapat();
        alarm.alarmAc();
    }

    void eveDonunce()
    {
        alarm.alarmKapat();
        elektrik.elektrikAc();
        tv.tvAc();
    }
};
```

* Kullanımı da olduktça basittir. İlk olarak **"EvFacade"** sınıfından bir nesne üretiyoruz. Ardından **"evdenDisariCikinca"** yada **"eveDonunce"** methodlarını, isteğimize uygun bir şekilde gerçekleştiriyoruz.

```cpp
int main()
{
    EvFacade evFacade;

    cout << "Evden İşe Gidiliyor ..." << endl;
    evFacade.evdenDisariCikinca();

    cout << "---------------------------------------------" << endl;

    cout << "Eve Giriliyor..." << endl;
    evFacade.eveDonunce();
}

```