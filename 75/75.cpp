#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
Dany jest tekst z³o¿ony ze s³ów zbudowanych z ma³ych liter alfabetu angielskiego. Metoda
szyfrowania afinicznego — dla której kluczem szyfruj¹cym s¹ dwie liczby ca³kowite A i B —
polega na wykonaniu kolejno nastêpuj¹cych operacji:
• zast¹pienia kolejnych liter alfabetu liczbami od 0 do 25: 'a' przez 0, 'b' przez 1, 'c'
  przez 2 itd. wed³ug przyporz¹dkowania przedstawionego w poni¿szej tabeli:
  a b c d e f g h i j k  l  m  n  o  p  q  r  s  t  u  v  w  x  y  z
  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
• pomno¿enia liczby odpowiadaj¹cej ka¿dej literze przez A i dodania otrzymanego wyniku
  do B, 
• zamiany otrzymanych liczb z powrotem na litery; jeœli liczba jest wiêksza ni¿ 25, bierze
  siê jej resztê z dzielenia przez 26. 
Parametry klucza, czyli liczby A i B, powinny byæ liczbami ca³kowitymi z przedzia³u [0, 25].
Dla przyk³adu, jeœli kluczem szyfruj¹cym jest (3, 7), czyli A = 3, zaœ B = 7, to litera 'n' jest
najpierw zastêpowana liczb¹ 13. Po pomno¿eniu jej przez A i dodaniu B otrzymujemy wynik
równy 46. W nastêpnym kroku otrzymujemy literê o numerze 46 – 26 = 20, czyli 'u'.
Okazuje siê, ¿e do odszyfrowania szyfru afinicznego mo¿na zastosowaæ tê sam¹ metodê, byæ
mo¿e z innym kluczem. Na przyk³ad, jeœli napis zaszyfrujemy kluczem (3, 7), to aby go odszyfrowaæ,
stosujemy ten sam algorytm z kluczem (9, 15). Dla przyk³adu, deszyfruj¹c literê
'u' z kluczem (9, 15), otrzymamy liczbê 20 * 9 + 15 = 195, czyli literê 'n', jako ¿e 195 mod 26
= 13. Klucz (9,15) jest wówczas kluczem deszyfruj¹cym dla klucza (3,7). 
*/

/* Wyniki
Zadanie 1:
did
desired
destroyed
devised
*/

/* Zadanie 1
W pliku tekst.txt dany jest, w pojedynczym wierszu, tekst z³o¿ony z dok³adnie 805 s³ów
zapisanych ma³ymi literami alfabetu angielskiego, oddzielonych znakami odstêpu. ¯adne
s³owo nie jest d³u¿sze ni¿ 15 znaków.
ZnajdŸ i wypisz te s³owa, których zarówno pierwsz¹, jak i ostatnia liter¹ jest 'd'. 
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("tekst.txt");
  string s;
  while (in >> s) {
    if (s[0] == 'd' && s[s.length() - 1] == 'd') cout << s << endl;
  }
  in.close();
  cout << endl;
}

int main() {
  z1();
}
