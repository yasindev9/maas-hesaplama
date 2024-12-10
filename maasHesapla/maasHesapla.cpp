#include <iostream>
#include <math.h>
#include <locale.h>
using namespace std;

int secim;
float saatUcret = 0;
float gunUcret = 0;
float ayUcret = 0;
int gunSaat;
int aySaat;
int mesaiSaat;
int eksikSaat;
bool firstRun = true;

enum secenekler {x, a, b, c};
int main()
{
	void gunlukHesap();
	void saatlikHesap();
	void aylikHesap();
	void printChar(char input, int a);
	enum secenekler secilen;
	setlocale(LC_ALL, "Turkish");
	if (firstRun == true)
	{
		cout << "***Maaş hesaplama programına hoşgeldiniz. Gerekli bilgileri doldurarak işlem seçin.***" << endl;
		cout << "!!!Programda hesaplanan verileri teyit etmeden aksiyon almayınız!!!" << endl;
		cout << "Günlük çalışma saatiniz : ";
		cin >> gunSaat;
		cout << "Aylık tam maaşınızı giriniz : ";
		cin >> ayUcret;
		aySaat = gunSaat * 30;
		gunUcret = ayUcret / aySaat;
		gunUcret *= gunSaat;
		saatUcret = gunUcret / gunSaat;
	}
	printChar('*', 90);
	cout << "Yapmak istediğiniz işlem türünü seçin:" << endl;
	cout << "1. Günlük ücret hesaplama" << endl << "2. Aylık net alacak hesaplama (Mesai/Eksik çalışma)" << endl << "3. Saatlik ücret hesaplama" << endl << "0. Çıkış" << endl;
	cin >> secim;
	secilen = static_cast<secenekler>(secim);
	switch (secilen)
	{
	case x:
		exit;
		break;
	case a:
		gunlukHesap();
		break;
	case b:
		aylikHesap();
		break;
	case c:
		saatlikHesap();
		break;
	default:
		cout << "hata";
		break;
	}
}

void gunlukHesap()
{
	firstRun = false;
	cout << ">>Günlük ücretiniz " << gunUcret << " birim olarak hesaplanmıştır. Ay 30 gün olarak kabul edilmiştir." << endl;
	main();
}

void aylikHesap()
{
	firstRun = false;
	cout << "Mesai ve/veya eksik çalışmalarınızı saat olarak belirtiniz" << endl;
	cout << "Aylık yaptığınız toplam mesai saati : ";
	cin >> mesaiSaat;
	cout << "Aylık toplam eksik çalışma saati : ";
	cin >> eksikSaat;
	ayUcret += saatUcret * mesaiSaat;
	ayUcret -= saatUcret * eksikSaat;
	cout << ">>Mesai ve eksik çalışmalarınız ile birlikte alacağınız " << ayUcret << " birim olarak hesaplanmıştır." << endl;
	main();
}

void saatlikHesap()
{
	firstRun = false;
	cout << ">>Saatlik ücretiniz " << saatUcret << " birim olarak hesaplanmıştır." << endl;

	main();
}

void printChar(char input, int a)
{
	for (int i = 0; i <= a; i++)
	{
		cout << input;
	}
	cout << endl;
}