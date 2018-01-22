#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
W pliku liczby1.txt znajduje siê 1000 liczb ca³kowitych dodatnich, zapisanych ósemkowo,
maksymalnie szeœciocyfrowych. Ka¿da liczba umieszczona jest w osobnym wierszu.
W pliku liczby2.txt znajduje siê 1000 liczb ca³kowitych dodatnich, zapisanych dziesiêtnie,
maksymalnie szeœciocyfrowych. Ka¿da liczba umieszczona jest w osobnym wierszu.
Napisz program(-y), za pomoc¹ którego(-ych) rozwi¹¿esz poni¿sze zadania. Do oceny oddaj
dokument wyniki.txt z rozwi¹zaniami poszczególnych zadañ oraz pliki Ÿród³owe programów
wykorzystanych do uzyskania rozwi¹zania. 
*/

/* Wyniki
61.2:
Min: 1002
Max: 777044
62.2:
Pierwszy element: 639
Liczba: 6
*/

const int SIZE = 1000;
int tab10[SIZE], tab8[SIZE];

int octToDec(int x) {
  int answer, counter = 1;
  while (x > 0) {
    answer += (x % 10 * counter);
    counter *= 8;
    x = x / 10;
  }
  return answer;
}

int decToOct(int x) {
  int answer, counter = 1;
  while (x > 0) {
    answer += (x % 8 * counter);
    counter *= 10;
    x = x / 8;
  }
  return answer;
}

/*
Wyszukaj w pliku liczby1.txt dwie liczby, najmniejsz¹ i najwiêksz¹. Podaj wartoœci
tych liczb w zapisie ósemkowym.
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  int min = 9999999;
  int max = 0;
  for (int i = 0; i < SIZE; i++) {
    if (tab8[i] > max) max = tab8[i];
    if (tab8[i] < min) min = tab8[i];
  }
  cout << "Najmniejsza: " << min << endl;
  cout << "Najwieksza: " << max << endl;
}

/*
ZnajdŸ najd³u¿szy niemalej¹cy ci¹g liczb wystêpuj¹cych w kolejnych wierszach pliku liczby2.txt.
Podaj pierwszy element tego ci¹gu oraz liczbê jego elementów. Mo¿esz za³o¿yæ,
¿e jest jeden taki ci¹g. 
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  int counter = 0, maxCounter = 0, firstNumber = 0;
  int maxFirst;
  for (int i = 1; i < SIZE; i++) {
    if (tab8[i] >= tab8[i - 1]) {
      counter++;
      if (firstNumber == 0) {
        firstNumber = tab8[i - 1];
        counter++;
      }
    }
    else {
      if (counter > maxCounter) {
        maxCounter = counter;
        maxFirst = firstNumber;
      }
      firstNumber = 0;
      counter = 0;
    }
  }
  cout << "Pierwszy element: " << maxFirst << endl;
  cout << "Liczba elementow: " << maxCounter << endl;
}

int main() {
  ifstream in("liczby1.txt");
  for (int i = 0; i < SIZE; i++) in >> tab8[i];
  in.close();
  in.open("liczby2.txt");
  for (int i = 0; i < SIZE; i++) in >> tab10[i];
  in.close();
  
  z1();
  z2();
}
