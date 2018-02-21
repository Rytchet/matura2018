#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
W pliku dane_trojkaty.txt znajduje siê 500 liczb ca³kowitych dodatnich. Ka¿da liczba
jest zapisana w osobnym wierszu, ¿adna liczba nie wystêpuje w pliku wiêcej ni¿ jeden raz.
Liczby podane w pliku dane_trojkaty.txt to d³ugoœci odcinków, z których bêdziemy
próbowaæ budowaæ trójk¹ty. 
*/

/* Wyniki

*/

const int SIZE = 500;
int tab[SIZE];

/* Zadanie 1
Wypisz wszystkie trójki kolejnych liczb z pliku dane_trojkaty.txt, które s¹ d³ugoœciami
boków trójk¹ta prostok¹tnego. 
*/

void wyswietl(int a, int b, int c) {
	cout << a << ", " << b << ", " << c << endl;
}

bool saDlugosciamiTrojkataProstokatnego(int a, int b, int c) {
	return (a * a + b * b == c * c ||
			a * a + c * c == b * b ||
			c * a + c * b == a * a);
}

void z1() {
	cout << "Zadanie 1:" << endl;
	for (int i = 0; i < SIZE - 2; i++) {
		if (saDlugosciamiTrojkataProstokatnego(tab[i], tab[i+1], tab[i+2])) {
			wyswietl(tab[i], tab[i+1], tab[i+2]);
		}
	}
	cout << endl;
}

int main() {
	ifstream in("dane_trojkaty.txt");
	for (int i = 0; i < SIZE; i++) {
		in >> tab [i];
	}
	in.close();
	
	z1();
}
