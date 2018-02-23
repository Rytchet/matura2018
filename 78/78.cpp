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

*/

string skrot(string wiadomosc) {
	int S[8] = {'A','L','G','O','R','Y','T','M'};
	while (wiadomosc.length() % 8 != 0) {
		wiadomosc += '.';
	}
	
	// Do pierwszego zadania
	cout << wiadomosc.length() << endl; 
	
	int j = 0;
	for (int i = 0; i < wiadomosc.length(); i++) {
		S[j] = (S[j] + wiadomosc[i]) % 128;
		j++;
		if (j == 8) j = 0;
	}
	string wynik = "";
	
	// Do pierwszego zadania
	for (int i = 0; i < 8; i++) {
		cout << S[i] << " ";
	}
	cout << endl;
	
	for (int j = 0; j < 8; j++) {
		wynik = wynik + (char) (65 + S[j] % 26);
	}
	return wynik;
}

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

void z1() {
	cout << "Zadanie 1: " << endl;
	string s = "W sieci mozna udawac wszystko z wyjatkiem tego co sie naprawde liczy. Nie mozesz udawac inteligencji, poczucia humoru ani blyskotliwosci, zlosliwosci, przewrotnosci, ani calej reszty twojej paskudnej, fascynujacej osobowosci.";
	cout << skrot(s) << endl;
}

int main() {
	z1();
}
