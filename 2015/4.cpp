#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Arkusze_egzaminacyjne/2015/formula_od_2015/MIN-R2_1P-152.pdf
W pliku liczby.txt znajduje siê 1000 liczb naturalnych zapisanych binarnie. Ka¿da
liczba zapisana jest w osobnym wierszu. Pierwsze piêæ wierszy zawiera nastêpuj¹ce liczby:
11010100111
11110111111011101
1010100111010100
1101111111111111111111010100101010101001
1010110011001101010011110101010101010111
Ka¿da liczba binarna zawiera co najwy¿ej 250 cyfr binarnych, co oznacza, ¿e w wielu
jêzykach programowania wartoœci niektórych z tych liczb nie da siê zapamiêtaæ
w pojedynczej zmiennej typu ca³kowitoliczbowego, np. w jêzyku C++ w zmiennej typu
int.
*/

const int SIZE = 1000;
string tab[SIZE];

/* Zadanie 1
Podaj, ile liczb z pliku liczby.txt ma w swoim zapisie binarnym wiêcej zer ni¿ jedynek.
Przyk³ad: Dla zestawu liczb:
101011010011001100111
10001001 <-
1000000 <-
101010011100
100010 <-
wynikiem jest liczba 3 (3 zaznaczone liczby maj¹ w swoim zapisie wiêcej zer ni¿ jedynek). 
*/

bool maWiecejZer(string s) {
	int zeroCounter = 0;
	int oneCounter = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '0') zeroCounter++;
		if (s[i] == '1') oneCounter++;
	}
	return zeroCounter > oneCounter;
}

void z1() {
	cout << "Zadanie 1:" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE; i++) {
		if (maWiecejZer(tab[i])) counter++;
	}
	cout << counter << endl << endl;
}

/* Zadanie 2
Podaj, ile liczb w pliku liczby.txt jest podzielnych przez 2 oraz ile liczb jest podzielnych
przez 8.
Przyk³ad: Dla zestawu liczb:
101011010011001100000 (*), (**)
10001001
100100 (*)
101010010101011011000 (*), (**)
100011
trzy liczby s¹ podzielne przez 2 (*) i dwie liczby s¹ podzielne przez 8 (**). 
*/

bool podzielnaPrzezDwa(string s) {
	return s[s.length() - 1] == '0';
}

bool podzielnaPrzezOsiem(string s) {
	return (s[s.length() - 1] == '0' && s[s.length() - 2] == '0' && s[s.length() - 3] == '0');
}

void z2() {
	cout << "Zadanie 2:" << endl;
	int counter2 = 0, counter8 = 0;
	for (int i = 0; i < SIZE; i++) {
		if (podzielnaPrzezDwa(tab[i])) counter2++;
		if (podzielnaPrzezOsiem(tab[i])) counter8++;
	}
	cout << "Podzielnych przez 2: " << counter2 << endl;
	cout << "Podzielnych przez 8: " << counter8 << endl << endl;
}

/* Zadanie 3
ZnajdŸ najmniejsz¹ i najwiêksz¹ liczbê w pliku liczby.txt. Jako odpowiedŸ podaj
numery wierszy, w których siê one znajduj¹.
Przyk³ad: Dla zestawu liczb:
101011010011001100111
10001001011101010
1001000
101010011100
1000110
najmniejsza liczba to: 1000110
najwiêksza liczba to: 101011010011001100111
Prawid³owa odpowiedŸ dla powy¿szego przyk³adu to: 5, 1. 
*/

void z3() {
	cout << "Zadanie 3:" << endl;
	int minLen = 999, maxLen = 0;
	for (int i = 0; i < SIZE; i++) {
		if (tab[i].length() < minLen) minLen = tab[i].length();
		if (tab[i].length() > maxLen) maxLen = tab[i].length();
	}
	string min = tab[0], max = tab[0];
	int minIndex, maxIndex;
	for (int i = 0; i < SIZE; i++) {
		if (tab[i].length() == minLen && tab[i] < min) {
			min = tab[i];
			minIndex = i + 1;
		}
		if (tab[i].length() == maxLen && tab[i] > max) {
			max = tab[i];
			maxIndex = i + 1;
		}
	}
	cout << "Numer wiersza najmniejszej: " << minIndex << endl;
	cout << "Numer wiersza najwiekszej: " << maxIndex << endl << endl;
}

int main() {
	ifstream in("liczby.txt");
	for (int i = 0; i < SIZE; i++) {
		in >> tab[i];
	}
	in.close();
	
	z1();
	z2();
	z3();
}
