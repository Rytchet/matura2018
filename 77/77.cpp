#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
W zadaniu rozwa¿amy teksty zbudowane tylko z wielkich liter alfabetu angielskiego, znaków
odstêpu i znaków przestankowych (przecinek, kropka). Oto litery alfabetu i numery ich pozycji
w alfabecie:
A B C D E F G H I J K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y  Z
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
Szyfrowanie Vigenere’a polega na zast¹pieniu ka¿dej litery tekstu Ÿród³owego liter¹ odleg³¹
od niej cyklicznie w alfabecie o k pozycji.
Wartoœæ k nie jest z góry ustalona dla ca³ego tekstu Ÿród³owego, lecz dla ka¿dej litery
w tekœcie jest okreœlana osobno, w oparciu o s³owo przyjête jako klucz szyfrowania.
Przystêpuj¹c do szyfrowania, nale¿y przyporz¹dkowaæ kolejnym literom tekstu Ÿród³owego
kolejne litery klucza, chodz¹c po nim cyklicznie, jeœli jest krótszy od szyfrowanego tekstu.
Znaki inne ni¿ litery nie s¹ szyfrowane, pomijamy je podczas przypisywania liter klucza. Pozycja
litery klucza w alfabecie jest t¹ wartoœci¹ k, o jak¹ nale¿y wykonaæ przesuniêcie
wzglêdem litery tekstu Ÿród³owego w celu znalezienia odpowiadaj¹cej jej litery szyfru. 
Przyk³ad
tekst Ÿród³owy: ”JEST OK”, klucz: ”EWA”
Tekst Ÿród³owy  J        E       S        T        spacja  O       K
Klucz           E        W       A        E                W       A
Pozycja klucza  4        22      0        4                22      0
Szyfr           J›4 = N  E›22=A  S›0 = S  T›4 = X  spacja  O›22=K  K›0 = K
wynik szyfrowania: ”NASX KK”. 
*/

/* Wyniki

*/

/* Zadanie 1
W pliku dokad.txt znajduje siê jeden wiersz z tekstem. D³ugoœæ tekstu nie przekracza
1024 znaków. Nale¿y zaszyfrowaæ ten tekst metod¹ Vigenere’a, u¿ywaj¹c jako klucza s³owa:
”LUBIMYCZYTAC”.
a) Podaj liczbê powtórzeñ klucza niezbêdn¹ do zaszyfrowania ca³ego tekstu Ÿród³owego
(uwzglêdniaj¹c w nich ostatnie rozpoczête powtórzenie).
b) Podaj zaszyfrowany tekst i zapisz go w pliku z odpowiedziami. 
'A' = 65 'Z' = 90
*/

string szyfruj(string s, string key) {
  string result;
  int keyIndex = 0;
  int move;
  int index;
  int counter = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] < 'A' || s[i] > 'Z') {
      result += s[i];
      continue;
    }
    move = (int) key[keyIndex] - 65;
    index = (int) s[i] - 65;
    index += move;
    if (index > 25) index = (index - 1) % 25;
    index += 65;
    result += (char) index;
    
    keyIndex++;
    if (keyIndex == key.length()) keyIndex = 0;
  }
  return result;
}

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("dokad.txt");
  string s = "";
  string temp;
  while (in >> temp) s += temp + " ";
  string key = "LUBIMYCZYTAC";
  
  
  cout << "a) " << 19 << endl; // Policzone dodaj¹c licznik do funkcji szyfruj
  cout << "b) " << szyfruj(s, key) << endl << endl;
}

/* Zadanie 2
W pliku szyfr.txt zapisano dwa wiersze. W pierwszym wierszu znajduje siê tekst zaszyfrowany
metod¹ Vigenere’a. W drugim wierszu znajduje siê klucz u¿yty do tego szyfrowania.
Szyfr zawiera wiele s³ów. Jego ³¹czna d³ugoœæ nie przekracza 1024 znaków. Szyfrowaniu
podlega³y tylko wielkie litery tekstu, zaœ odstêpy i znaki przestankowe pozosta³y bez zmiany. 
Odszyfruj tekst i umieœæ jego postaæ Ÿród³ow¹ w pliku z odpowiedziami. 
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  string key = "ZLODZIEJCZASU"; // wyciête z pliku
  string s = "";
  string temp;
  ifstream in("szyfr.txt");
  while (in >> temp) s += temp + " ";
  
  int keyIndex = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == ' ' || s[i] == ',' || s[i] == '.') continue;
    s[i] -= key[keyIndex];
    s[i] += 65;
    if (s[i] < 'A') s[i] += 26;
    keyIndex++;
    if (keyIndex == key.length()) keyIndex = 0;
  }
  cout << s << endl;
}

int main() {
  z1();
  z2();
}
