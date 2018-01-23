#include <iostream>
#include <fstream>
using namespace std;

/* Tresæ
W pliku ciagi.txt w oddzielnych wierszach znajduje siê 1000 ró¿nych ci¹gów zerojedynkowych,
ka¿dy o d³ugoœci od 2 do 18. Napisz program(-y), który pozwoli rozwi¹zaæ
poni¿sze zadania. Nastêpnie je rozwi¹¿, a odpowiedzi do poszczególnych zadañ zapisz w pliku
tekstowym wyniki_ciagi.txt. Wyniki do ka¿dego zadania poprzedŸ numerem oznaczaj¹cym
to zadanie. 
*/

/* Wyniki

*/

const int SIZE = 1000;
string tab[SIZE];

/*
Ci¹giem dwucyklicznym bêdziemy nazywaæ taki ci¹g zerojedynkowy w o d³ugoœci parzystej,
który sk³ada siê z dwóch fragmentów w1 oraz w2, w = w1 + w2, takich ¿e w1 = w2. Podaj
wszystkie ci¹gi dwucykliczne zapisane w pliku ciagi.txt.
Przyk³ad
Dla zestawu ci¹gów:
10010101010011001010101001 <-
11001101001
1001000
11001100 <-
101010011100
110011110011 <-
3 zaznaczone ci¹gi s¹ dwucykliczne
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  int length;
  string w1, w2;
  for (int i = 0; i < SIZE; i++) {
    length = tab[i].length();
    if (length % 2 != 0) continue;
    w1 = tab[i].substr(0, length / 2);
    w2 = tab[i].substr(length / 2, length / 2);
    if (w1 == w2) {
      cout << tab[i] << endl;
    }
  }
}

int main() {
  ifstream in("ciagi.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  
  z1();
}
