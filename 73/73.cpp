#include <iostream> // std::fixed
#include <fstream>
#include <iomanip> // setprecision()
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

/* Zadanie 2
Sporz¹dŸ statystykê czêstotliwoœci wystêpowania liter w tekœcie: dla ka¿dej litery podaj liczbê
jej wyst¹pieñ we wszystkich s³owach tekstu oraz jej procentowy udzia³ wœród wyst¹pieñ
wszystkich liter w tekœcie(do statystyki nie wliczaj spacji). OdpowiedŸ zapisz w nastêpuj¹cej
postaci:
A: 632 (7.56%) // 'A' = (char) 65
B: 196 (2.34%)
...
Wartoœci procentowe podaj w zaokr¹gleniu do dwóch miejsc po przecinku. 
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  int counter[26];
  float allCounter = 0;
  for (int i = 0; i < 26; i++) counter[i] = 0;
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < tab[i].length(); j++) {
      counter[tab[i][j] - 65]++;
      allCounter++;
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << (char) (i + 65) << ": " << counter[i] << " (";
    cout << fixed << setprecision(2) << counter[i] / allCounter * 100 << "%)";
    cout << endl;
  }
  cout << endl;
}

int main() {
  ifstream in("tekst.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  
  z1();
  z2();
}
