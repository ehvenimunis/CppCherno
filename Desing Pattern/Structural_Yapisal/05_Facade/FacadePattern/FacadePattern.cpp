//============================================================================
// İsim        : 05_Facade
// Yazan       : Muhammed Salih Aydoğan     
// Version     : 1.0
// Copyright   : 
// Açıklama    : Facade Pattern
//============================================================================
#include <string>
#include <iostream>

using namespace std;

/* Operasyonları tanımlıyoruz. Biz projemizde "Alarm", "Elektrik", "Tv" işlemleri tanımladık.*/
class Alarm
{
public:
    void alarmAc()
    {
        cout << "Alarm Open. Your home safety..." << endl;
    }

    void alarmKapat()
    {
        cout << "Alarm Closed..." << endl;
    }
};

class Elektrik
{
public:
    void elektrikAc()
    {
        cout << "Electric Open..." << endl;
    }

    void elektrikKapat()
    {
        cout << "Electric Close..." << endl;
    }
};

class Tv
{
public:
    void tvAc()
    {
        cout << "Tv Open..." << endl;
    }

    void tvKapat()
    {
        cout << "TV Close..." << endl;
    }
};

/* 
Bu sınıf içinde oluşturduğumuz "Alarm", "Elektrik", "Tv" sınıflarından nesneler yarattık. Bu sınıfımızda iki fonksiyonumuz bulunmakta. İlki "evdenDisariCikinca" methodu, ilk belirlediğimiz sınıflardan, evden çıkınca yapılacak olan işlemleri tanımlamakta. Diğeri "eveDonunce" methodu eve geri dönünce yapıalcak olan işlemleri barındırmaktadır.
*/
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

int main()
{ 
    /* Bir alt sistemin parçalarını oluşturan classları istemciden soyutlayarak kullanımı daha da kolaylaştırıyoruz */
    EvFacade evFacade;

    cout << "Evden Gidiliyor ..." << endl;
    evFacade.evdenDisariCikinca();

    cout << "---------------------------------------------" << endl;

    cout << "Eve Giriliyor..." << endl;
    evFacade.eveDonunce();
}


/*

    Evden Gidiliyor ...
    Electric Close...
    TV Close...
    Alarm Open. Your home safety...
    ---------------------------------------------
    Eve Giriliyor...
    Alarm Closed...
    Electric Open...
    Tv Open...
*/