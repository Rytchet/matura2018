#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
W pliku tekst.txt dany jest tekst z³o¿ony ze s³ów pisanych wielkimi literami alfabetu
angielskiego. S³ów jest 1876, oddzielone s¹ one pojedynczymi odstêpami, a inne znaki poza
literami i spacjami w tekœcie nie wystêpuj¹. Napisz program(-y), który poda odpowiedzi do
poni¿szych zadañ. Odpowiedzi zapisz w pliku wyniki.txt. 
*/

/* Wyniki

*/

const int SIZE = 1876;
string tab[SIZE];

/* Zadanie 1
Oblicz, ile jest w tekœcie s³ów, w których wystêpuj¹ dwie kolejne takie same litery. 
*/

bool hasTwoLetters (string s) {
  for (int i = 1; i < s.length(); i++) {
    if (s[i] == s[i - 1]) return true;
  }
  return false;
}

void z1() {
  cout << "Zadanie 1:" << endl;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (hasTwoLetters(tab[i])) counter++;
  }
  cout << counter << endl << endl;
}

int main() {
  ifstream in("tekst.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  
  z1();
}
