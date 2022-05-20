# Bridge Pattern

**"Bridge Pattern"**, arabirimi uygulanmasından ayırmak için kullanılır. Bunu yapmak esneklik sağlar, böylece her ikisi de bağımsız olarak değişebilir. Yani soyutlanmış (abstract) yapıyı implementasyonundan (uygulamasından) ayırmaya, bağımsız olarak geliştirilebilir iki yapı elde etmemize yarar.

## Bridge Ne Zaman Devreye Girer?

Kalıtım üzerine kurulu sistemler vardır ve doğası gereği bu yapıların bir dezavantajı da kapsüllemeyi kırmasıdır.
İstemci kodunu, implementasyonundan ayırmak için soyutlamayı kullanır ve genel olarak da kalıtımdan yararlanmaktayız. Bu işlemleri gerçekleştirirken de bir arayüz veya soyut bir sınıf tanımlarız ve ondan miras hiyerarşileri yaratırız. Her ne kadar ilk bakışta bu yaklaşım mantıklı görünse de ve yanlış bir şey olmasa da, miras yoluyla soyutlamalar her zaman esnek değildir. Kalıtım kullandığımızda, uygulamayı kalıcı olarak soyutlamaya bağlarız. Sonuç olarak, birinde yapılan herhangi bir değişiklik diğerini etkiler. Buradaki daha esnek bir yol, soyutlamayı ve uygulamayı ayırmaktır ve bridge tasarım deseni bu noktada devreye girer.

Senaryo olarak kullanıcıların metin veya e-posta mesajı gibi farklı türde mesajlar göndermek için kullanabileceği bir mesajlaşma uygulamasını düşünelim. Sezgisel olarak Mesaj adında temel bir interface ya da abstract class oluşturmak ardından da sınıfları bunlardan türetmek gerekiyor. Türetilmiş sınıflarımız; TextMessage ve EmailMessage olacaktır. Son olarak da e-posta ve metin mesajını gönderme senaryolarını yapacağımız için TextMessage sınıfından türeyen bir TextMessageSender ve EmailMessage sınıfından türeyen EmailMessageSender sınıflarını oluştururduk. Oluşturacağımız yapı aşağıdaki gibi olacaktır.

## Bridge Pattern Kullanım Adımları

* İlk olarak, **"CizimAPISablon"** isminde bir soyut sınıf tanımlıyoruz.

```cpp
class CizimAPISablon
{
  public:
    virtual void cemberCiz(double x, double y, double yaricap) = 0;
};
```

* Ardından bu sınıftan miras alan **"CizimAPI1"**, **"CizimAPI2"** sınıflarını oluşturuyoruz. Bu sınıflar, **"cemberCiz"** methodunu kendine göre yorumlamaya olanak sağlamaktadır.

```cpp
class CizimAPI1 : public CizimAPISablon
{
  public:
    void cemberCiz(double x, double y, double yaricap) override
    {
        cout << "CizimAPI1 Verileri x:  " << x << " y :" << y << " yarı çap : " << yaricap << endl;
    }
};

class CizimAPI2 : public CizimAPISablon
{
  public:
    void cemberCiz(double x, double y, double yaricap) override
    {
        cout << "CizimAPI2 Verileri x:  " << x << " y :" << y << " yarı çap : " << yaricap << endl;
    }
};
```

* Ardından **"Sekil"** isminde soyut bir sınıf oluşturyoruz. Bu sınıf, **"ciz"** ve **"boyutArttir"** isminde iki methodu bulunmakta.

```cpp
class Sekil
{
  public:
    virtual void ciz() = 0;
    virtual void boyutArttir(double boyutlandir) = 0;
};
```

* Son olarak **"Sekil"** sınıfından türetilen **"DaireSekil"** için gerekli sınıfı hazırlıyoruz. Bu sınıf constructor ile verileri almakta. Ardından soyut sınıftan gelen methodlar ile işlemlerimizi gerçekleştiriyoruz.

```cpp
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
```

* Kullanım oldukça kolaydır. İlk olarak **"DaireSekil"** sınıfından nesne üretiyoruz. Nesne üretirken **"x"**, **"y"**, **"yarıçap"** ve **"CizimAPI"** türünde nesne veriyoruz. Ardından **"boyutArttir"** ve **"ciz"** methodlarını, verdiğimiz **""CizimAPI"** türünde işlemler etabi tutmuş oluyoruz. 

```cpp
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
```
