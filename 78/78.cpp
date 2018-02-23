#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Materialy/Zbiory_zadan/Matura_Zbi%C3%B3r_zada%C5%84_Informatyka.pdf
Za d³uga do wklejenia

W pliku wiadomosci.txt znajduje siê 11 wiadomoœci, ka¿da w osobnym wierszu. Liczba
znaków ka¿dej wiadomoœci nie przekracza 255. Wiadomoœci zawieraj¹ znaki pojedynczego
odstêpu, które s¹ integraln¹ czêœci¹ informacji.

W pliku podpisy.txt znajduje siê 11 wierszy, ka¿dy z nich zawiera 8 liczb ca³kowitych,
stanowi¹cych elementy podpisu elektronicznego jednej wiadomoœci. Liczby w wierszu oddzielone
s¹ pojedynczymi znakami odstêpu. Kolejnoœæ wierszy podpisów jest zgodna z kolejnoœci¹
wierszy wiadomoœci (pierwszy wiersz podpisów odpowiada pierwszej wiadomoœci,
drugi — drugiej itd.) 
*/

/* Wyniki
Zadanie 1:
232
12 94 94 57 96 115 51 90
MQQFSLZM

Zadanie 2:
MQQFSLZM
WWXRFKEC
UAQFAKQN
WVTFWMLI
WMXQBVTU
IRCEIIDN
DLGULFST
UIZVEUSE
DMWHUXTH
UFHRHSXM
TFUKGFXW

Zadanie 3:
1
3
4
8
9
11
*/

bool zadaniePierwsze = true;

/* Zadanie 1
Wyznacz skrót pierwszej wiadomoœci z pliku wiadomosci.txt i udokumentuj wyniki
kolejnych etapów obliczania tego skrótu. Zapisz w kolejnych wierszach pliku wynikowego:
	a) liczbê znaków wiadomoœci po jej uzupe³nieniu do najmniejszej d³ugoœci
o wielokrotnoœci 8 znaków,
	b) wartoœci liczbowe 8 kolejnych bajtów skrótu (elementy tablicy S) po przetworzeniu
ca³ej wiadomoœci — wszystkie wartoœci w jednym wierszu, oddzielone pojedynczymi
znakami odstêpu,
	c) skrót wiadomoœci w postaci napisu o d³ugoœci 8, z³o¿onego z wielkich liter alfabetu
angielskiego. 
*/

string skrot(string wiadomosc) {
	int S[8] = {'A','L','G','O','R','Y','T','M'};
	while (wiadomosc.length() % 8 != 0) {
		wiadomosc += '.';
	}
	
	if (zadaniePierwsze) cout << wiadomosc.length() << endl; 
	
	int j = 0;
	for (int i = 0; i < wiadomosc.length(); i++) {
		S[j] = (S[j] + wiadomosc[i]) % 128;
		j++;
		if (j == 8) j = 0;
	}
	string wynik = "";
	
	if (zadaniePierwsze) {
		for (int i = 0; i < 8; i++) {
			cout << S[i] << " ";
		}
		cout << endl;
	}
	
	for (int j = 0; j < 8; j++) {
		wynik = wynik + (char) (65 + S[j] % 26);
	}
	return wynik;
}



void z1() {
	cout << "Zadanie 1: " << endl;
	ifstream in("wiadomosci.txt");
	string s;
	getline(in, s);
	cout << skrot(s) << endl << endl;
	zadaniePierwsze = false;
}

/* Zadanie 2
Odszyfruj skróty wiadomoœci ze wszystkich podpisów elektronicznych umieszczonych
w pliku podpisy.txt, stosuj¹c algorytm A z kluczem publicznym (d,n) = (3,200). Zapisz
uzyskane skróty w kolejnych, osobnych wierszach pliku z odpowiedziami. 
*/

string odszyfrujSkrot(int tab[], int d, int n) {
	string ans = "";
	for (int i = 0; i < 8; i++) {
		tab[i] = (tab[i] * 3 % 200);
		ans += (char) tab[i];
	}
	return ans;
}

void z2() {
	cout << "Zadanie 2:" << endl;
	ifstream in("podpisy.txt");
	int tab[8];
	string ans;
	for (int q = 0; q < 11; q++) { // 11 kluczy w pliku
		for (int i = 0; i < 8; i++) {
			in >> tab[i];
		}
		ans = odszyfrujSkrot(tab, 3, 200);
		cout << ans << endl;
	}
	cout << endl;
}

/* Zadanie 3
Zweryfikuj wiarygodnoœæ wszystkich wiadomoœci i podaj numery wiadomoœci wiarygodnych.
Zapisz w jednym wierszu pliku z odpowiedziami, jako liczby z zakresu 1..11, zgodnie z kolejnoœci¹
umieszczenia ich w pliku danych, oddzielone pojedynczym znakiem odstêpu. 
*/

void z3() {
	cout << "Zadanie 3:" << endl;
	ifstream inWiadomosc("wiadomosci.txt");
	ifstream inPodpis("podpisy.txt");
	string wiadomosc;
	int tab[8];
	for (int i = 0; i < 11; i++) {
		getline(inWiadomosc, wiadomosc);
		for (int j = 0; j < 8; j++) inPodpis >> tab[j];
		if (skrot(wiadomosc) == odszyfrujSkrot(tab, 3, 200)) cout << i + 1 << endl;
	}
	cout << endl;
}

int main() {
	z1();
	z2();
	z3();
}
