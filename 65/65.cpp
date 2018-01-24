#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

/* Treœæ
W pliku dane_ulamki.txt znajduje siê 1000 par liczb naturalnych dodatnich, mniejszych
ni¿ 12 000. Ka¿da para liczb jest zapisana w osobnym wierszu, liczby w wierszu rozdzielone
s¹ pojedynczym znakiem odstêpu. Parê liczb zapisanych w tym samym wierszu interpretujemy
jako u³amek, którego licznikiem jest pierwsza liczba, a mianownikiem — druga liczba. 
*/

/* Wyniki
65.1: 1, 225
65.2: 410
65.3: 128446
65.4: 578219135
*/

const int SIZE = 1000;
float tab[SIZE][2];

/* Zadanie 1
Podaj u³amek o minimalnej wartoœci. Jeœli w pliku wystêpuje wiêcej ni¿ jeden taki u³amek, to
podaj ten spoœród nich, który ma najmniejszy mianownik. Twoja odpowiedŸ powinna zawieraæ
parê liczb oznaczaj¹c¹ licznik i mianownik u³amka. 
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  float minLicznik = 999999999, minMianownik = 999999999, minUlamek = 999999999;
  float ulamek;
  for (int i = 0; i < SIZE; i++) {
    ulamek = tab[i][0] / tab[i][1];
    if (ulamek <= minUlamek) {
      if (ulamek == minUlamek && tab[i][1] > minMianownik) continue;
      minUlamek = ulamek;
      minLicznik = tab[i][0];
      minMianownik = tab[i][1];
    }
  }
  cout << "Licznik: " << minLicznik << " Mianownik: " << minMianownik << endl;
}

/* Zadanie 2
Podaj liczbê zapisanych w pliku u³amków, które zosta³y podane w postaci nieskracalnej. 
*/

int nwd(int x, int y) {
  if (x < y) return nwd(y, x);
  if (y == 0) return x;
  return nwd(y, x % y);
}

void z2() {
  cout << endl << "Zadanie 2: " << endl;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (nwd(tab[i][0], tab[i][1]) > 1) continue;
    counter++; 
  }
  cout << counter << endl << endl;
}

/* Zadanie 3
Zapis danych w postaci nieskracalnej uzyskamy, zamieniaj¹c ka¿dy u³amek na jego postaæ
nieskracaln¹. Podaj sumê liczników wszystkich podanych w pliku u³amków, jak¹ otrzymalibyœmy
po sprowadzeniu u³amków do nieskracalnej postaci.
*/

void z3() {
  cout << "Zadanie 3: " << endl;
  int sum = 0, currentNwd;
  for (int i = 0; i < SIZE; i++) {
    float licznik = tab[i][0];
    float mianownik = tab[i][1];
    while (nwd(licznik, mianownik) > 1) {
      currentNwd = nwd(licznik, mianownik);
      licznik = licznik / currentNwd;
      mianownik = mianownik / currentNwd;
    }
    sum += licznik;
  }
  cout << sum << endl;
}

/* Zadanie 4
U³amki w pliku zosta³y tak dobrane, ¿e ka¿dy mianownik jest dzielnikiem liczby
b=2^2*3^2*5^2*7^2*13, a wartoœæ ka¿dego u³amka jest nie wiêksza ni¿ 3. Oznacza to, ¿e sumê
wszystkich u³amków mo¿na przedstawiæ jako u³amek , którego mianownikiem jest
b=2^2*3^2*5^2*7^2*13. Wyznacz sumê u³amków ze wszystkich wierszy i podaj licznik takiego
u³amka, ¿e suma u³amków jest równa a/b
*/

void z4() {
  cout << endl << "Zadanie 4:" << endl;
  int b = pow(2, 2) * pow(3, 2) * pow(5, 2) * pow(7, 2) * 13;
  long long int razy, sum = 0;
  long long int licznik, mianownik;
  for (int i = 0; i < SIZE; i++) {
    licznik = tab[i][0];
    mianownik = tab[i][1];
    razy = b / mianownik;
    licznik = licznik * razy;
    sum += licznik;
  }
  cout << "a = " << sum << endl;
}

int main() {
  ifstream in("dane_ulamki.txt");
  for (int i = 0; i < SIZE; i++) {
    in >> tab[i][0] >> tab[i][1];
  }
  in.close();
  
  z1();
  z2();
  z3();
  z4();
}
