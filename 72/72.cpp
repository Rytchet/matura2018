#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
W pliku napisy.txt znajduje siê 200 wierszy, z których ka¿dy zawiera dwa napisy
o d³ugoœci od 1 do 50 znaków, oddzielone pojedynczym odstêpem. Napisy sk³adaj¹ siê wy³¹cznie
z ma³ych liter alfabetu angielskiego.
Napisz program (lub kilka programów), który pozwoli rozwi¹zaæ poni¿sze zadania. Odpowiedzi
zapisz w pliku wyniki.txt. 
*/

/* Wyniki
Zadanie 1:
feycznvjtboxfx gthzgbpglrwjqxqlculgwzdhuevrmvssozrwdjcqcb
70

Zadanie 2:
kxazlp kxazlpe
e
ifvjhuqvh ifvjhuqvhcupzcpw
cupzcpw
aznqxr aznqxryrbgshtceaylwak
yrbgshtceaylwak

Zadanie 3:
15
zccvywdcmjrdokqzcnayixplhkrf sarkqzcnayixplhkrf
iokvlepqzeyvycfjkliiutmzqawwjxgf dfcfyddwodduznkmivqxnrdliiutmzqawwjxgf
psmwjyystgwchofokzvmkmgusfakroambngky mabgusfakroambngky
*/

const int SIZE = 200;

/* Zadanie 1
Oblicz, w ilu wierszach jeden (którykolwiek) z napisów jest przynajmniej trzy razy d³u¿szy
od drugiego. Jako odpowiedŸ wypisz liczbê takich wierszy oraz parê napisów z pierwszego
z nich. 
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("napisy.txt");
  string a, b;
  bool flag = true;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b;
    if (a.length() * 3 <= b.length() || b.length() * 3 <= a.length()) {
      if (flag) {
        cout << a << " " << b << endl;
        flag = false;
      }
      counter++;
    }
  }
  cout << counter << endl << endl;
}

/* Zadanie 2
ZnajdŸ (i wypisz) wszystkie takie wiersze pliku, w których drugi napis da siê otrzymaæ
z pierwszego przez dopisanie na jego koñcu pewnej dodatniej liczby liter (na przyk³ad kot
i kotara). Dla ka¿dego wiersza podaj oba znajduj¹ce siê w nim napisy, a osobno wypisz 
litery, które nale¿y dopisaæ. 
*/

bool compareTask2(string a, string b) {
  if (b.length() <= a.length()) return false;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) return false;
  }
  return true;
}

void z2() {
  cout << "Zadanie 2:" << endl;
  ifstream in("napisy.txt");
  string a, b;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b;
    if (compareTask2(a, b)) {
      cout << a << " " << b << endl;
      for (int j = a.length(); j < b.length(); j++)
        cout << b[j];
      cout << endl;
    }
  }
  cout << endl;
}

/* Zadanie 3
Niektóre z podanych par napisów maj¹ identyczne zakoñczenia (na przyk³ad komputer i krater).
ZnajdŸ i wypisz najwiêksz¹ mo¿liw¹ d³ugoœæ takiego zakoñczenia, a tak¿e wszystkie
pary napisów w wierszach, które osi¹gaj¹ tê maksymaln¹ d³ugoœæ. 
*/

int commonEndingLen(string a, string b) {
  int counter = 0;
  for (int i = 1; i < a.length() && i < b.length(); i++) {
    if (a[a.length() - i] == b[b.length() - i]) counter++;
    else return counter;
  }
  return counter;
}

void z3() {
  cout << "Zadanie 3:" << endl;
  ifstream in("napisy.txt");
  string a, b;
  int maxLen = 0;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b;
    if (commonEndingLen(a, b) > maxLen) maxLen = commonEndingLen(a, b);
  }
  in.close();
  cout << maxLen << endl;
  in.open("napisy.txt");
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b;
    if (commonEndingLen(a, b) == maxLen) cout << a << " " << b << endl;
  }
  cout << endl;
}

int main() {
  z1();
  z2();
  z3();
}
