#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

/* Treœæ 
Plik wierzcholki.txt zawiera 100 wierszy. W ka¿dym wierszu zapisano 6 liczb ca³kowitych
z przedzia³u <–100; 100>, bêd¹cych wspó³rzêdnymi trzech ró¿nych punktów: A, B i C
w kartezjañskim uk³adzie wspó³rzêdnych (odpowiednio xa, ya, xb, yb, xc, yc). Liczby w wierszu
s¹ oddzielone pojedynczymi znakami tabulacji.
Podobny plik wierzcholkiTR.txt zawiera równie¿ 100 wierszy. W ka¿dym wierszu
zapisano 6 liczb ca³kowitych nale¿¹cych do przedzia³u <–100; 100>, bêd¹cych wspó³rzêdnymi
trzech wierzcho³ków trójk¹ta ABC (odpowiednio xa, ya, xb, yb, xc, yc). Liczby w wierszu s¹
oddzielone pojedynczymi znakami tabulacji. 
*/

/* Wyniki
Zadanie 1:
2

Zadanie 2:
24

Zadanie 3:
-30, 23; 75, -62; 25, 48
Obwod: 316.34

Zadanie 4:
18

Zadanie 5: / Tylko ostatnie wspó³rzêdne zgadzaj¹ siê z kluczem
-5, 7; 42, 48; -1, -7; -48, -48
-2, 27; -6, -23; -3, -49; 1, 1
-42, -46; 1, -34; 5, -26; -38, -38
-14, 49; 27, 39; 48, -3; 7, 7
*/

const int SIZE = 100;
int tab[SIZE][6];

/* Zadanie 1
Podaj liczbê wierszy z pliku wierzcholki.txt, w których wszystkie zapisane punkty
le¿¹ w I æwiartce uk³adu wspó³rzêdnych i nie nale¿¹ do osi OX i OY.
*/

void z1() {
	cout << "Zadanie 1:" << endl;
	int counter = 0;
	bool flag;
	for (int i = 0; i < SIZE; i++) {
		flag = true;
		for (int j = 0; j < 6; j++) {
			if (tab [i][j] <= 0) flag = false;
		}
		if (flag) counter++;
	}
	cout << counter << endl << endl;
}

/* Zadanie 2
Podaj liczbê wierszy z pliku wierzcholki.txt, w których zapisane s¹ wspó³rzêdne punktów
le¿¹cych na jednej prostej.

Ten wzór nie by³ podany w poleceniu ale jest chyba w tablicach (wzór na wspó³czynnik kieunkowy):
a = (yb - ya) / (xb - xa)

Trzeba go przy porównaniu przekszta³ciæ ¿eby nie wystêpowa³o ewentualne dzielenie przez 0
*/

void z2() {
	cout << "Zadanie 2:" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE; i++) {
		int x1 = tab[i][0];
		int y1 = tab[i][1];
		int x2 = tab[i][2];
		int y2 = tab[i][3];
		int x3 = tab[i][4];
		int y3 = tab[i][5];
		if ((y2 - y1) * (x3 - x2) == (y3 - y2) * (x2 - x1)) { // Ze wzoru z polecenia
			counter++;
		}
	}
	cout << counter << endl << endl;
}

/* Zadanie 3
Podaj (z pliku wierzcholkiTR.txt) wspó³rzêdne wierzcho³ków trójk¹ta o najwiêkszym
obwodzie oraz obwód tego trójk¹ta. Obwód zaokr¹glij do dwóch miejsc po przecinku. Uwaga:
mo¿esz za³o¿yæ, ¿e jest tylko jeden taki trójk¹t.
Wzór na odleg³oœæ punktów: d = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))
*/

void z3() {
	cout << "Zadanie 3:" << endl;
	double max = 0;
	int xa, ya, xb, yb, xc, yc;
	double d1, d2, d3;
	double obwod;
	for (int i = 0; i < SIZE; i++) {
		d1 = sqrt(pow(tab[i][0] - tab[i][2], 2) + pow(tab[i][1] - tab[i][3], 2));
		d2 = sqrt(pow(tab[i][0] - tab[i][4], 2) + pow(tab[i][1] - tab[i][5], 2));
		d3 = sqrt(pow(tab[i][2] - tab[i][4], 2) + pow(tab[i][3] - tab[i][5], 2));
		obwod = d1 + d2 + d3;
		if (obwod > max) {
			max = obwod;
			xa = tab[i][0];
			ya = tab[i][1];
			xb = tab[i][2];
			yb = tab[i][3];
			xc = tab[i][4];
			yc = tab[i][5];
		} 
	}
	cout << xa << ", " << ya << "; " << xb << ", " << yb << "; " << xc << ", " << yc << endl;
	cout << "Obwod: " << setprecision(5) << max << endl << endl;
}

/* Zadanie 4
Dla ka¿dego wiersza z pliku wierzcholkiTR.txt sprawdŸ, czy punkty zapisane w tym
wierszu s¹ wierzcho³kami pewnego trójk¹ta prostok¹tnego. Podaj liczbê trójk¹tów prostok¹tnych
zapisanych w tym pliku
Uwaga: Takich trójk¹tów jest wiêcej ni¿ cztery.
*/

void z4() {
	cout << "Zadanie 4:" << endl;
	int counter = 0;
	double d1, d2, d3;
	for (int i = 0; i < SIZE; i++) {
		d1 = pow(tab[i][0] - tab[i][2], 2) + pow(tab[i][1] - tab[i][3], 2);
		d2 = pow(tab[i][0] - tab[i][4], 2) + pow(tab[i][1] - tab[i][5], 2);
		d3 = pow(tab[i][2] - tab[i][4], 2) + pow(tab[i][3] - tab[i][5], 2);
		if (d1 + d2 == d3 ||
			d1 + d3 == d2 ||
			d3 + d2 == d1) { // Bez potêgowania tutaj i bez podzielenia wy¿ej bo w c++ wychodz¹ niedok³adne wyniki
			counter++;
		}
	}
	cout << counter << endl << endl;
}

/* Zadanie 5
Dla ka¿dego wiersza z pliku wierzcholkiTR.txt, w
których zapisane s¹ kolejno wspó³rzêdne punktów A, B i C,
wyznacz wspó³rzêdne punktu D, tak aby czworok¹t ABCD
by³ równoleg³obokiem. Podaj wspó³rzêdne wszystkich wierzcho³ków
czworok¹tów ABCD, których punkt D le¿y na prostej y=x. 
Spoko rysunek w zbiorze.
Hint: Trzeba dzia³aæ na przek¹tnych
*/

void z5() {
	cout << "Zadanie 5:" << endl;
	int deltaAx, deltaAy, x, y;
	for (int i = 0; i < SIZE; i++) {
		x = tab[i][0] + tab[i][4] - tab[i][2]; // xa + xc = xb + xd
		y = tab[i][1] + tab[i][5] - tab[i][3]; // ya + yc = yb + yd
		if (x == y) {
			cout << tab[i][0] << ", " << tab[i][1] << "; ";
			cout << tab[i][2] << ", " << tab[i][3] << "; ";
			cout << tab[i][4] << ", " << tab[i][5] << "; ";
			cout << x << ", " << y << endl;
		}
	}
	cout << endl;
}

int main() {
	ifstream in("wierzcholki.txt");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < 6; j++) {
			in >> tab[i][j];
		}
	}
	in.close();
	
	z1();
	z2();
	
	in.open("wierzcholkiTR.txt");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < 6; j++) {
			in >> tab[i][j];
		}
	}
	in.close();
	
	z3();
	z4();
	z5();
}
