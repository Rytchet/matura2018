#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
Dwa napisy a i b s¹ swoimi anagramami, je¿eli napis a (napis b) mo¿na zapisaæ za pomoc¹
liter wystêpuj¹cych w napisie b (napisie a), wykorzystuj¹c wszystkie jego litery.
W pliku dane_napisy.txt znajduje siê 1000 par napisów, z których ka¿dy jest d³ugoœci
od 2 do 20 znaków, sk³adaj¹cych siê z wielkich liter: A, B, C, D, E, F, G, H, I, J. Ka¿da para
napisów jest zapisana w osobnym wierszu, a napisy oddzielone s¹ pojedynczym znakiem odstêpu.
*/

/* Wyniki

*/

const int SIZE = 1000;

/* Zadanie 1
Napis nazywamy jednolitym, je¿eli wszystkie jego litery s¹ takie same. Przyk³adem takiego
napisu jest AAAA. Podaj liczbê wierszy zawieraj¹cych parê napisów jednolitych, które s¹
wzajemnie swoimi anagramami.
*/

bool isJednolity(string s) {
  char c = s[0];
  for (int i = 0; i < s.length(); i++)
    if (s[i] != c) return false;
  return true;
}



int main() {
  ifstream in("dane_napisy.txt");
  string a, b;
  int jednolityCounter = 0;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b;
    if (isJednolity(a) && isJednolity(b) && a.length() == b.length())
      jednolityCounter++;
  }
  
  cout << "Zadanie 1:" << endl;
  cout << jednolityCounter << endl << endl;
}
