// 2022

#include <iostream>

using namespace std;

void kare_al(int* id);
void kare_al_(int& id);

int idizi[5] = { 5, 17, 21, 52, 75 };

int& ref_al(int id) {
	// idizi dizisinin id değişkeni ile gösterilen indeksinde yer alan değerin referansını geri döndürür.
	return idizi[id];
}

class sinif {
	int id;

public:
	sinif(int pid);
	~sinif();
	void kare(sinif& nes)
	{
		nes.id = nes.id * nes.id;
		cout << nes.id << endl;
	}
	void deger_goster() { cout << id << endl; }
};

sinif::sinif(int pid)
{
	id = pid;
	cout << "Nesne oluşturuluyor: " << id << endl;
}

sinif::~sinif()
{
	cout << endl << endl << "Nesne yok ediliyor: " << id << endl;
}


int main(void)
{
	/*  İşaretçi kullanarak referans yoluyla fonksiyona parametre geçirme  */
	int id;

	id = 21;

	kare_al(&id); // İşaretçi kullanarak parametre geçirme (değişken adresi geçirilir)

	cout << "main() fonksiyonu içindeki id değişken değeri: " << id;


	/*  Referans kullanarak referans yoluyla fonksiyona parametre geçirme  */
	cout << endl << endl;

	int id_;

	id_ = 21;

	kare_al_(id_); // Referans kullanarak parametre geçirme

	cout << "main() fonksiyonu içindeki id değişken değeri: " << id_ << endl;

	/*  Nesneleri fonksiyonlara referans yoluyla geçirme */
	cout << endl << endl;

	sinif nes(21);

	cout << "kare() fonksiyonu içindeki değer: ";
	nes.kare(nes);

	cout << "main() fonksiyonu içindeki değer: ";
	nes.deger_goster();

	/*  Fonksiyonlardan referans döndürme  */
	cout << endl << endl;

	cout << idizi[2] << endl;

	// idizi dizisinin 3.elemanının değerini değiştirir.
	ref_al(2) = 41; // idizi[2] = 41; işlem satırı ile aynı işlemi yapar.

	cout << idizi[2];

	return 0;
}

void kare_al(int* id)
{
	*id = (*id) * (*id);

	cout << "Bellek adresi: " << id << endl;
	cout << "kare_al() fonksiyonu içindeki değişken değeri: " << *id << endl;
}

void kare_al_(int& id)
{
	id = id * id;

	cout << "Bellek adresi: " << &id << endl;
	cout << "kare_al_() fonksiyonu içindeki değişken değeri: " << id << endl;
}


/*

Bellek adresi: 000000FF210FF514
kare_al() fonksiyonu iindeki de­i■ken de­eri: 441
main() fonksiyonu iindeki id de­i■ken de­eri: 441

Bellek adresi: 000000FF210FF534
kare_al_() fonksiyonu iindeki de­i■ken de­eri: 441
main() fonksiyonu iindeki id de­i■ken de­eri: 441


Nesne olu■turuluyor: 21
kare() fonksiyonu iindeki de­er: 441
main() fonksiyonu iindeki de­er: 441


21
41

Nesne yok ediliyor: 441

*/