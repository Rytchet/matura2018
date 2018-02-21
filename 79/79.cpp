#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/* Treœæ
Okrag na plaszczyznie reprezentujemy za pomoca trzech liczb x, y, r ,gdzie (x, y (oznaczaja
wspólrzedne srodka okregu, a r — jego promien.
W pliku okregi.txt danych jest 2000 okregów; kazdy zapisany jest w osobnym wierszu,
zawierajacym trzy liczby rzeczywiste x, y, r (-10^9 <= x, y <= 10^9, 0 < r > 10^9). 
*/

/* Wyniki
Zadanie 1:
I: 1339
II: 274
III: 166
IV: 218
0: 3

Zadanie 2:
158

Zadanie 3:
231

6, 3, 11, 7, 4, 5, 12, 36, 18, 53, 87, 21, 73, 39, 31, 12, 41, 10, 64, 22, 57, 31, 41, 50, 65, 73, 45, 18, 37, 28
Najdluzszy: 87
*/

const int SIZE = 2000;
double tab[SIZE][3];

/* Zadanie 1
Podaj liczbe okregów, które calkowicie zawieraja sie w I, II, III i IV cwiartce ukladu wspól-
rzednych. Podaj równiez liczbe okregów, które nie zawieraja sie w calosci w zadnej cwiartce,
tzn. maja co najmniej jeden punkt wspólny z jedna z osi Ox lub Oy. Jako odpowiedz wypisz
piec liczb: liczba okregów I cwiartki, liczba okregów II cwiartki, liczba okregów III cwiartki,
liczba okregów IV cwiartki oraz liczba okregów, które nie zawieraja sie w calosci w zadnej
cwiartce. 

  II | I
 --------
 III | IV
 
*/

bool jestCwiartka(double x, double y, double r) {
  return (abs(x) > r && abs(y) > r);
}

void z1() {
  cout << "Zadanie 1:" << endl;
  int counter1 = 0, counter2 = 0, counter3 = 0, counter4 = 0, counter0 = 0;
  for (int i = 0; i < SIZE; i++) {
    float x = tab[i][0], y = tab[i][1], r = tab[i][2];
    if (jestCwiartka(x, y, r)) {
      if (x > 0 && y > 0) counter1++;
      if (x < 0 && y > 0) counter2++;
      if (x < 0 && y < 0) counter3++;
      if (x > 0 && y < 0) counter4++;
    }
    else counter0++;
  }
  cout << "I: " << counter1 << endl;
  cout << "II: " << counter2 << endl;
  cout << "III: " << counter3 << endl;
  cout << "IV: " << counter4 << endl;
  cout << "0: " << counter0 << endl;
  cout << endl;
}

/* Zadanie 2
Powiemy, ¿e dwa okrêgi tworz¹ lustrzan¹ parê, jeœli jeden z nich powstaje przez odbicie drugiego
wzglêdem jednej z osi Ox lub Oy. Podaj liczbê lustrzanych par spoœród wszystkich
okrêgów zapisanych w pliku okregi.txt. 
*/

bool saLustrzane(double x1, double y1, double r1, double x2, double y2, double r2) {
	if (r1 != r2) return false;
	if (x1 == x2 && y1 == y2) return false;
	if (abs(x1) == abs(x2) && y1 == y2) return true;
	if (abs(y1) == abs(y2) && x1 == x2) return true;
	return false;
}

void z2() {
	cout << "Zadanie 2:" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (saLustrzane(tab[i][0], tab[i][1], tab[i][2], tab[j][0], tab[j][1], tab[j][2])) {
				counter++;
			}
		}
	}
	cout << counter << endl << endl;
}

/* Zadanie 3
Powiemy, ¿e dwa okrêgi tworz¹ prostopad³¹ parê, jeœli jeden z nich powstaje przez obrót
drugiego o 90 stopni wzglêdem œrodka uk³adu wspó³rzêdnych.
Przyk³ad: okrêgi o œrodkach w punktach (3,-5), (5,3) (i o tych samych promieniach) tworz¹
parê prostopad³¹
Podaj liczbê prostopad³ych par okrêgów spoœród wszystkich okrêgów zapisanych w pliku
okregi.txt. 
*/

bool saProstopadle(double x1, double y1, double r1, double x2, double y2, double r2) {
	if (r1 != r2) return false;
	if (x1 == x2 && y1 == y2) return false;
	if (abs(x1) == abs(y2) && x2 == y1) return true;
	if (abs(x2) == abs(y1) && x1 == y2) return true;
	return false;
}

void z3() {
	cout << "Zadanie 3:" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE - 1; i++) {
		for (int j = i + 1; j < SIZE; j++) {
			if (saProstopadle(tab[i][0], tab[i][1], tab[i][2], tab[j][0], tab[j][1], tab[j][2])) {
				counter++;
			}
		}
	}
	cout << counter << endl << endl;
}

/* Zadanie 4
Powiemy, ¿e ci¹g okrêgów tworzy ³añcuch, jeœli kolejne okrêgi tego ci¹gu maj¹ ze sob¹ co
najmniej jeden punkt wspólny; przyjmujemy, ¿e ci¹g zawieraj¹cy tylko jeden okr¹g równie¿
tworzy ³añcuch
ZnajdŸ d³ugoœci wszystkich ³añcuchów tworzonych przez okrêgi zapisane w wierszach
o numerach od 1 do 1000. Podaj d³ugoœæ najd³u¿szego ³añcucha. 
*/

double odlegloscMiedzyPunktami(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void z4() {
	cout << "Zadanie 4:" << endl;
	int lancuch = 0;
	int max = 0;
	for (int i = 0; i < 1000; i++) {
		lancuch++;
		if (lancuch > max) max = lancuch;
		if (odlegloscMiedzyPunktami(tab[i][0], tab[i][1], tab[i+1][0], tab[i+1][1]) <= tab[i][2]) {
			continue;
		}
		else {
			cout << lancuch << ", ";
			lancuch = 0;
		}
	}
	cout << endl << "Najdluzszy: " << max << endl << endl;
}

int main() {
  ifstream in("okregi.txt");
  double a, b, c;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b >> c;
    tab[i][0] = a;
    tab[i][1] = b;
    tab[i][2] = c;
  }
  in.close();
  
  z1();
  z2();
  z3();
  z4();
}
