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
72.1:
70
feycznvjtboxfx gthzgbpglrwjqxqlculgwzdhuevrmvssozrwdjcqcb
72.2:
kxazlp kxazlpe
e
ifvjhuqvh ifvjhuqvhcupzcpw
cupzcpw
aznqxr aznqxryrbgshtceaylwak
yrbgshtceaylwak
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

int main() {
  z1();
  z2();
}
