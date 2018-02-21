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
Zadanie 1:
4, 3, 5
13, 85, 84
33, 65, 56
28, 45, 53

Zadanie 2:
29694

Zadanie 3:
2343790
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

/* Zadanie 2
Podaj najwiêkszy obwód trójk¹ta, którego boki maj¹ d³ugoœci równe liczbom wystêpuj¹cym
w ró¿nych wierszach pliku dane_trojkaty.txt. 
*/

bool saTrojkatem(int a, int b, int c) {
	return (a + b > c && a + c > b && b + c > a);
}

void z2() {
	cout << "Zadanie 2:" << endl;
	int max = 0;
	for (int i = 0; i < SIZE - 2; i++) {
		for (int j = i + 1; j < SIZE - 1; j++) {
			for (int k = j + 1; k < SIZE; k++) {
				if (saTrojkatem(tab[i], tab[j], tab[k])) {
					int obwod = tab[i] + tab[j] + tab[k];
					if (obwod > max) max = obwod;
				}
			}
		}
	}
	cout << max << endl << endl;
}

/* Zadanie 3
Podaj, ile nieprzystaj¹cych trójk¹tów mo¿na utworzyæ z odcinków o d³ugoœciach podanych
w pliku dane_trojkaty.txt. 
Uwaga: Dwa trójk¹ty s¹ przystaj¹ce wtedy i tylko wtedy, gdy trzy boki jednego trójk¹ta s¹
odpowiednio równe trzem bokom drugiego trójk¹ta, np. trójk¹t o bokach (10, 18, 15) jest
przystaj¹cy z trójk¹tem o bokach (18, 15, 10). 
*/

void z3() {
	cout << "Zadanie 3:" << endl;
	int counter = 0;
	for (int i = 0; i < SIZE - 2; i++) {
		for (int j = i + 1; j < SIZE - 1; j++) {
			for (int k = j + 1; k < SIZE; k++) {
				if (saTrojkatem(tab[i], tab[j], tab[k])) counter++;
			}
		}
	}
	cout << counter << endl << endl;
}

int main() {
	ifstream in("dane_trojkaty.txt");
	for (int i = 0; i < SIZE; i++) {
		in >> tab [i];
	}
	in.close();
	
	z1();
	z2();
	z3();
}
