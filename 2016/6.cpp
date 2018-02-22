#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2016/formula_od_2015/MIN-R2_1P-162.pdf
Podstawieniowy szyfr Cezara z przesuniêciem (kluczem) k polega na zast¹pieniu ka¿dego
znaku jawnego znakiem le¿¹cym w alfabecie o k pozycji w prawo od zastêpowanego znaku.
Przyk³ad: znak ‘B’ po zakodowaniu kluczem k=3 zast¹piony zostanie znakiem ‘E’. 
Przy szyfrowaniu znaku nale¿y postêpowaæ w sposób cykliczny, to znaczy, je¿eli znak nie
posiada w alfabecie nastêpnika przesuniêtego o k pozycji, to alfabet „zawija siê" i za liter¹ Z
nastêpuje znów litera A.
Przyk³ad: jawny znak ‘X’ po zakodowaniu kluczem k=3 zast¹piony zostanie znakiem ‘A’,
znak ‘Y’ – znakiem ‘B’, natomiast ‘Z’ – znakiem ‘C’. 
W tym zadaniu rozpatrujemy tylko s³owa zbudowane z wielkich liter alfabetu angielskiego
(o kodach ASCII odpowiednio od 65 do 90), o d³ugoœciach nie wiêkszych ni¿ 30 znaków. 
*/

/* Zadanie 1
W pliku dane_6_1.txt znajduje siê 100 s³ów. S³owa umieszczono w osobnych wierszach.
Fragment pliku dane_6_1.txt:
INTERPRETOWANIE
ROZWESELANIE
KONSERWOWANIE
Napisz program, który zaszyfruje s³owa z pliku dane_6_1.txt z u¿yciem klucza
k = 107. Wynik zapisz do pliku wyniki_6_1.txt, ka¿de s³owo w osobnym wierszu,
w porz¹dku odpowiadaj¹cym kolejnoœci s³ów z pliku z danymi.
Uwaga:
Dla pierwszego s³owa z pliku dane_6_1.txt (INTERPRETOWANIE) wynikiem jest
s³owo LQWHUSUHWRZDQLH. 
*/

string cipher(string s, int k) {
	int n;
	for (int i = 0; i < s.length(); i++) {
		n = (int) s[i]; // Zmiana typu bo char ma tylko 8 bitów
		n -= 65;
		n += k;
		n %= 26;
		n += 65;
		s[i] = (char) n;
	}
	return s;
}

void z1() {
	ifstream in("dane_6_1.txt");
	// ofstream out("wyniki_6_1.txt", ios::app);
	string s, result;
	while (in >> s) {
		result = cipher(s, 107);
		// cout << result << endl;
		// out << result << endl;
	}
}

/* Zadanie 2
W pliku dane_6_2.txt zapisano 3 000 szyfrogramów i odpowiadaj¹ce im klucze
szyfruj¹ce. W ka¿dym wierszu znajduje siê jeden szyfrogram (zaszyfrowane s³owo)
i po pojedynczym znaku odstêpu odpowiadaj¹cy mu klucz (maksymalnie czterocyfrowa
liczba). 
Fragment pliku dane_6_2.txt:
BCYKUNCM 1718
YFOGNSKGYW 7580
WARDA 9334 
Napisz program, który odszyfruje s³owa zaszyfrowane podanymi kluczami. Wynik zapisz
w pliku wyniki_6_2.txt: ka¿de odszyfrowane s³owo w osobnym wierszu, w porz¹dku
odpowiadaj¹cym kolejnoœci szyfrogramów z pliku z danymi. 
Dla pierwszego szyfrogramu z pliku dane_6_2.txt (BCYKUNCM) wynikiem jest s³owo
ZAWISLAK. 
*/

string decipher(string s, int k) {
	k = k % 26;
	k = 26 - k;
	return cipher(s, k);
}

void z2() {
	ifstream in("dane_6_2.txt");
	// ofstream out("wyniki_6_2.txt", ios::app);
	string s, result;
	int k;
	while (in >> s >> k) {
		result = decipher(s, k);
		// cout << result << endl;
		// out << result << endl;
	}
}

/* Zadanie 3
W pliku dane_6_3.txt zapisano 3 000 par s³ów, po jednej parze w wierszu, oddzielonych
pojedynczym znakiem odstêpu. Drugie s³owo w ka¿dej parze jest szyfrogramem pierwszego
z nieznanym kluczem.
Niektóre szyfrogramy s¹ b³êdne, co oznacza, ¿e niektóre litery w s³owie zakodowano
z ró¿nymi przesuniêciami. S³owo ma zawsze tê sam¹ d³ugoœæ co odpowiadaj¹cy
mu szyfrogram.
Fragment pliku dane_6_3.txt:
ZAWISLAK EFBNXQFP
KRASZEWSKI XENFMRJFXV
Napisz program, który wyszuka i wypisze te s³owa z pliku dane_6_3.txt, które b³êdnie
zaszyfrowano. Wynik zapisz w pliku wyniki_6_3.txt: ka¿de s³owo w osobnym wierszu,
w porz¹dku odpowiadaj¹cym kolejnoœci tych s³ów z pliku z danymi.
Uwaga:
Pierwsze s³owo w pliku wynikowym to SMIGIELSKI. 
*/

char cipher(char c, int k) {
	int n;
	n = (int) c;
	n -= 65;
	n += k;
	n %= 26;
	n += 65;
	c = (char) n;
	return c;
}

void z3() {
	ifstream in("dane_6_3.txt");
	// ofstream out("wyniki_6_3.txt");
	string s, c;
	int key;
	bool flag;
	while (in >> s >> c) {
		flag = false;
		if (s.length() != c.length()) flag = true;
		for (int i = 0; i < 26; i++) {
			if (cipher(s[0], i) == c[0]) key = i;
		}
		for (int i = 0; i < s.length(); i++) {
			if (cipher(s[i], key) != c[i]) flag = true;
		}
		if (flag) {
			// cout << s << endl;
			// out << s << endl;
		}
	}
}

int main() {
	z1();
	z2();
	z3();
}
