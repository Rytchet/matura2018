#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
Rozwa¿amy szyfrowanie przestawieniowe, w którym kluczem jest n-elementowa tablica zawieraj¹ca
ró¿ne liczby ca³kowite z przedzia³u [1, n]. Na przyk³ad kluczem 5-elementowym
mo¿e byæ tablica [3, 2, 5, 4, 1].
Szyfrowanie napisu A (o d³ugoœci co najmniej n) kluczem n-elementowym P[1..n] odbywa siê
w nastêpuj¹cy sposób:
• pierwsza litera s³owa A zamieniana jest miejscami z liter¹ na pozycji P[1],
• nastêpnie druga litera s³owa A zamieniana jest z liter¹ na pozycji P[2]
• itd.
Uzyskane na koñcu s³owo jest szyfrem napisu A z kluczem P. 
138 Egzamin maturalny. Informatyka. Poziom rozszerzony. Zbiór zadañ
Jeœli napis A ma wiêcej ni¿ n liter, to po n-tym kroku powy¿szego algorytmu kolejn¹ literê
zamieniamy znów z liter¹ na pozycji P[1] itd. Oznacza to, ¿e w i-tym kroku zamieniamy litery
na pozycjach i oraz P[1+(i-1) mod n]. 
// Polecam spojrzeæ do zbioru, jest obrazek z lepszym wyjaœnieniem
Napis „KAAYTRNFOIM” jest zatem szyfrem napisu „INFORMATYKA” z kluczem [3, 2, 5, 4, 1]. 
*/

/* Wyniki

*/

/* Zadanie 1
W pliku szyfr1.txt dane s¹:
• w wierszach o numerach od 1 do 6 — napisy z³o¿one z 50 liter alfabetu ³aciñskiego;
• w wierszu nr 7 — klucz 50-elementowy; liczby oddzielone s¹ pojedynczym odstê-
pem.
Zaszyfruj wszystkie szeœæ napisów zgodnie z opisan¹ metod¹. Wynik, czyli zaszyfrowane
napisy, zapisz w osobnych wierszach w pliku wyniki_szyfr1.txt. 
*/

string szyfruj(string s, int key[], int keyLen) {
  char temp;
  int keyIndex = 0;
  for (int i = 0; i < s.length(); i++) {
    temp = s[i];
    s[i] = s[key[keyIndex] - 1];
    s[key[keyIndex] - 1] = temp;
    keyIndex++;
    if (keyIndex == keyLen) keyIndex = 0;
  }
  return s;
}

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("szyfr1.txt");
  string tab[6];
  int key[50];
  for (int i = 0; i < 6; i++) in >> tab[i];
  for (int i = 0; i < 50; i++) in >> key[i];
  
  for (int i = 0; i < 6; i++) cout << szyfruj(tab[i], key, 50) << endl;
  cout << endl;
}

/* Zadanie 2
W pliku szyfr2.txt dane s¹:
• w pierwszym wierszu — napis z³o¿ony z 50 liter alfabetu ³aciñskiego;
• w drugim wierszu — klucz 15-elementowy; liczby oddzielone s¹ pojedynczym odstê-
pem.
Zaszyfruj dany napis zgodnie z opisan¹ metod¹. Wynik, czyli zaszyfrowany napis, zapisz
w pliku wyniki_szyfr2.txt. 
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  ifstream in ("szyfr2.txt");
  string s;
  in >> s;
  int key[15];
  for (int i = 0; i < 15; i++) in >> key[i];
  cout << szyfruj(s, key, 15) << endl;
}

int main() {
  z1();
  z2();
}
