#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

/* Treœæ
W pliku hasla.txt danych jest 200 hase³ u¿ytkowników pewnego systemu. Ka¿dy u¿ytkownik
posiada jedno has³o (ka¿de zapisane jest w osobnym wierszu), które zawiera od 1 do
20 znaków alfanumerycznych, tzn. cyfr od 0 do 9 lub liter alfabetu ³aciñskiego (ma³ych lub
du¿ych). Polityka bezpieczeñstwa systemu wymaga, aby has³a by³y odpowiednio skomplikowane
i nie powtarza³y siê.
Poni¿ej podano pierwsze piêæ hase³ zapisanych w pliku hasla.txt:
ZXUhkPLcjKo
ikfLDegQXj
8Y7JGYXXR5
603624722555
50q4252ax5
*/

/* Wyniki
Zadanie 1:
16
Zadanie 2:
8Y7JGYXXR5
Ehz018657
PAsCMQaervw
cefdi
cek
ikfLDegQXj
jir
yvm249t83o04
*/

const int SIZE = 200;
string tab[SIZE];

/* Zadanie 1
Podaj liczbê hase³ z³o¿onych jedynie ze znaków numerycznych, tzn. cyfr od 0 do 9.
*/

bool isNumeric(char c) {
  return (c >= '0' && c <= '9');
}

bool isOnlyNumeric(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (!isNumeric(s[i])) return false;
  }
  return true;
}

void z1() {
  cout << "Zadanie 1:" << endl;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (isOnlyNumeric(tab[i])) counter++;
  }
  cout << counter << endl << endl;
}

/* Zadanie 2
Wypisz has³a, które zosta³y u¿yte przez co najmniej dwóch ró¿nych u¿ytkowników, tzn. wystêpuj¹ce
w dwóch ró¿nych wierszach. Has³a wypisz (bez powtórzeñ) w kolejnoœci leksykograficznej.
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (i == j) continue;
      if (tab[i] == tab[j]) {
        cout << tab[i] << endl;
        i++;
        break;
      }
    }
  }
}

int main() {
  ifstream in("hasla.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  sort(tab, tab + SIZE);

  z1();
  z2();
}
