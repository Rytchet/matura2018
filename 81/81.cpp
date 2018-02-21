#include <iostream>
#include <fstream>
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

int main() {
	ifstream in("wierzcholki.txt");
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < 6; j++) {
			in >> tab[i][j];
		}
	}
	in.close();
	
	z1();
}
