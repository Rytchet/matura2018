#include <iostream>
#include <fstream>
using namespace std;

/*
W pliku liczby.txt znajduje siê 1000 trójek liczb ca³kowitych dodatnich rozdzielonych
pojedynczymi odstêpami, ka¿da trójka – w osobnym wierszu. Liczby zapisane w pliku nale¿¹
do przedzia³u [1, 32 767]. 
*/


/* Zadanie 1
Podaj, w ilu wierszach pliku z danymi liczby w trójkach s¹ uporz¹dkowane rosn¹co. 
*/

void z1() {
	cout << "Zadanie 1:" << endl;
	ifstream in("liczby.txt");
	int a, b, c;
	int counter = 0;
	while (in >> a >> b >> c) {
		if (a < b && b < c) counter++;
	}
	cout << counter << endl << endl;
}

/* Zadanie 2
Dla ka¿dego wiersza wyznacz najwiêkszy wspólny dzielnik (NWD) trójki liczb w nim
zapisanych i podaj sumê tych dzielników. 
*/

int nwd(int x, int y) {
	if (x < y) return nwd(y, x);
	if (y == 0) return x;
	return nwd(y, x % y);
}

void z2() {
	cout << "Zadanie 2:" << endl;
	ifstream in("liczby.txt");
	int a, b, c;
	int sum = 0;
	while (in >> a >> b >> c) {
		sum += nwd(nwd(a, b), nwd(b, c));
	}
	cout << sum << endl << endl;
}

/* Zadanie 3
Dla ka¿dego wiersza oblicz sumê cyfr wszystkich liczb znajduj¹cych siê w tym wierszu.
Podaj:
	• liczbê wierszy, dla których suma cyfr ze wszystkich trzech zapisanych liczb jest równa
	  35;
	  
	• najwiêksz¹ sumê cyfr w wierszu oraz liczbê wierszy, w których suma cyfr równa jest
	  tej najwiêkszej wartoœci. 
*/

int sumOfNumbers(int a) {
	int sum = 0;
	while (a > 0) {
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

void z3() {
	cout << "Zadanie 3:" << endl;
	ifstream in("liczby.txt");
	int a, b, c;
	int counter35 = 0;
	int sum, maxSum = 0, maxSumCounter = 0;
	while (in >> a >> b >> c) {
		sum = sumOfNumbers(a) + sumOfNumbers(b) + sumOfNumbers(c);
		if (sum == 35) counter35++;
		if (sum > maxSum) {
			maxSum = sum;
			maxSumCounter = 0;
		}
		if (sum == maxSum) maxSumCounter++;
	}
	cout << "Liczba wierszy z suma 35: " << counter35 << endl;
	cout << "Najwieksza suma cyfr: " << maxSum << endl;
	cout << "Ilosc wierszy z najwieksza suma: " << maxSumCounter << endl << endl;
}

int main() {
	z1();
	z2();
	z3();
}
