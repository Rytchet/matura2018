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

Zadanie 3:
39

Zadanie 4:
40
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
  cout << endl;
}

/* Zadanie 3
Podaj liczbê u¿ytkowników posiadaj¹cych has³a, w których wystêpuje fragment z³o¿ony
z czterech kolejnych znaków ASCII (w dowolnej kolejnoœci).
Przyk³ady hase³ zawieraj¹cych taki fragment to:
A5mnpoR89cd (mnpo)
A5876RRcg (5876)
As45FGHFEk90nba (GHFE)
*/

bool has4ascii(string s) {
  if (s.length() < 4) return false;
  char t[4];
  for (int i = 0; i < s.length(); i++) {
    t[0] = (int) s[i];
    t[1] = (int) s[i + 1];
    t[2] = (int) s[i + 2];
    t[3] = (int) s[i + 3];
    sort(t, t + 4);
    if (t[0] + 1 == t[1] && t[1] + 1 == t[2] && t[2] + 1 == t[3]) return true;
  }
  return false;
}

void z3() {
  cout << "Zadanie 3:" << endl;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (has4ascii(tab[i])) {
      counter++;
      // cout << tab[i] << endl;
    }
  }
  cout << counter << endl << endl;
}

/* Zadanie 4
Podaj liczbê hase³, które spe³niaj¹ jednoczeœnie poni¿sze warunki:
• has³o zawiera co najmniej jeden znak numeryczny, tzn. cyfrê od 0 do 9,
• has³o zawiera co najmniej jedn¹ ma³¹ literê,
• has³o zawiera co najmniej jedn¹ du¿¹ literê. 
*/

bool isSafe(string s) {
  bool numberFlag = false, smallFlag = false, bigFlag = false;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9') numberFlag = true;
    if (s[i] >= 'a' && s[i] <= 'z') smallFlag = true;
    if (s[i] >= 'A' && s[i] <= 'Z') bigFlag = true;
  }
  return (numberFlag && smallFlag && bigFlag);
}

void z4() {
  cout << "Zadanie 4:" << endl;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (isSafe(tab[i])) counter++;
  }
  cout << counter << endl << endl;
}

int main() {
  ifstream in("hasla.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  sort(tab, tab + SIZE);

  z1();
  z2();
  z3();
  z4();
}
