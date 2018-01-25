#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
Binarny fraktal Fibonacciego to dwuwymiarowa tablica zawieraj¹ca w kolejnych wierszach
binarne zapisy kolejnych liczb Fibonacciego, gdzie ka¿de zero w zapisie zast¹piono bia³ym
kwadratem, a ka¿d¹ jedynkê czarnym kwadratem (p. rysunek). Wszystkie binarne zapisy powinny
sk³adaæ siê z jednakowej liczby cyfr, czyli do zapisów krótszych ni¿ najd³u¿szy nale¿y
dodaæ zera wiod¹ce. 
Napisz program komputerowy, za pomoc¹ którego uzyskasz odpowiedzi do poni¿szych zadañ.
Rysunek fraktala (zadanie nr 3) wykonaj, wykorzystuj¹c dostêpne narzêdzia informatyczne.
Odpowiedzi do poszczególnych zadañ zapisz w pliku tekstowym o nazwie wyniki.txt,
natomiast rysunek fraktala w pliku fraktal.xxx, gdzie xxx oznacza rozszerzenie
pliku, w którym zapisany jest obraz fraktala. 
*/

/* Wyniki

*/

const int SIZE = 40;
int tab[SIZE];
ofstream out("test.txt", ios::app);

/* Zadanie 1
Podaj wartoœci F10, F20, F30, F40. Zapisz ka¿d¹ z liczb w osobnym wierszu
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  cout << tab[9] << endl << tab[19] << endl << tab[29] << endl;
  cout << tab[39] << endl << endl;
  
  out << "Zadanie 1:" << endl;
  out << tab[9] << endl << tab[19] << endl << tab[29] << endl;
  out << tab[39] << endl << endl;
}

/* Zadanie 2
ZnajdŸ wszystkie liczby pierwsze wœród liczb F1, F2, … , F40. Zapisz ka¿d¹ z liczb w osobnym
wierszu. 
*/

bool isPrime(int n) {
  if (n <= 1) return false;
  else if (n % 2 == 0 && n != 2) return false;
  for (int i = 3; i * i <=n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

void z2() {
  cout << "Zadanie 2:" << endl;
  out << "Zadanie 2:" << endl;
  for (int i = 0; i < SIZE; i++) {
    if (isPrime(tab[i])) {
      cout << tab[i] << endl;
      out << tab[i] << endl;
    }
  }
  cout << endl;
  out << endl;
}

/* Zadanie 3
Dla pierwszych 40 liczb Fibonacciego utwórz binarny fraktal Fibonacciego:
• Wypisz reprezentacjê binarn¹ wszystkich liczb Fibonacciego od F1 do F40.
• Wyrównaj d³ugoœci reprezentacji binarnych wszystkich liczb Fibonacciego od F1 do
  F40 i na ich podstawie sporz¹dŸ obraz binarnego fraktala Fibonacciego.    
*/

string toBinary(int n) {
  string result = "";
  while (n > 0) {
    if (n % 2 == 1) result = "1" + result;
    else result = "0" + result;
    n /= 2;
  }
  return result;
}

void z3() {
  cout << "Zadanie 3:" << endl;
  out << "Zadanie 3:" << endl;
  string bin;
  int length = toBinary(tab[39]).length();
  for (int i = 0; i < SIZE; i++) {
    bin = toBinary(tab[i]);
    while (bin.length() < length) {
      bin = "0" + bin;
    }
    cout << bin << endl;
    out << bin << endl;
  }
  cout << endl;
  out << endl;
}

int main() {
  tab[0] = 1;
  tab[1] = 1;
  for (int i = 2; i < SIZE; i++) {
    tab[i] = tab[i - 1] + tab[i - 2]; 
  }
  
  z1();
  z2();
  z3();
  
  out.close();
}
