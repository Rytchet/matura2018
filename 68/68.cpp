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
68.1: 9
68.2: 93
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

/* Zadanie 2
Podaj liczbê wierszy, które zawieraj¹ napisy bêd¹ce wzajemnie swoimi anagramami. 
*/

string sort(string s) {
  char temp;
  for (int i = 0; i < s.length() - 1; i++) {
    for (int j = 0; j < s.length() - 1; j++) {
      if (s[j] > s[j + 1]) {
        temp = s[j];
        s[j] = s[j + 1];
        s[j + 1] = temp;
      }
    }
  }
  return s;
}

bool areAnagrams(string a, string b) {
  if (a.length() != b.length()) return false;
  a = sort(a);
  b = sort(b);
  return a == b;
}

int main() {
  ifstream in("dane_napisy.txt");
  string a, b;
  int jednolityCounter = 0;
  int anagramCounter = 0;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b;
    if (isJednolity(a) && isJednolity(b) && a.length() == b.length())
      jednolityCounter++;
      
    if (areAnagrams(a, b)) anagramCounter++;
  }
  cout << "Zadanie 1:" << endl;
  cout << jednolityCounter << endl << endl;
   
  cout << "Zadanie 2:" << endl;
  cout << anagramCounter << endl << endl;
}
