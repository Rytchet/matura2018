#include <iostream>
#include <fstream>
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

double abs(double n) {
  if (n >= 0) return n;
  return -n;
}

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
}
