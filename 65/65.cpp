#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
W pliku dane_ulamki.txt znajduje siê 1000 par liczb naturalnych dodatnich, mniejszych
ni¿ 12 000. Ka¿da para liczb jest zapisana w osobnym wierszu, liczby w wierszu rozdzielone
s¹ pojedynczym znakiem odstêpu. Parê liczb zapisanych w tym samym wierszu interpretujemy
jako u³amek, którego licznikiem jest pierwsza liczba, a mianownikiem — druga liczba. 
*/

/* Wyniki
65.1: 1, 225
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

int main() {
  ifstream in("dane_ulamki.txt");
  for (int i = 0; i < SIZE; i++) {
    in >> tab[i][0] >> tab[i][1];
  }
  in.close();
  
  z1();
  z2();
}
