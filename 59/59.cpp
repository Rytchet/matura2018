#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/* Treœæ
Input: "wyniki_liczby.txt"
1000 ró¿nych liczb od 2 do 9 cyfr
*/

/* Wyniki
59.1: 122
*/

const int SIZE = 1000;
int tab[SIZE];

/*
Czynnikiem pierwszym danej liczby naturalnej z³o¿onej jest dowolna liczba 
pierwsza, która dzieli tê liczbê ca³kowicie. Podaj, ile jest w pliku liczby.txt 
liczb, w których rozk³adzie na czynniki pierwsze wystêpuj¹ dok³adnie trzy ró¿ne 
czynniki (mog¹ siê one powtarzaæ), z których ka¿dy jest nieparzysty.
*/

void z1() {
  cout << endl << "Zadanie 1: " << endl;
  int n, primeCount, numberCount = 0;
  bool flag;
  for (int i = 0; i < SIZE; i++) {
    primeCount = 0;
    n = tab[i];
    flag = true;
    while (n != 1) {
      if (n % 2 == 0) {
        flag = false;
        break;
      }
      for (int i = 3; i <= n; i = i + 2) {
        if (n % i == 0) {
          primeCount++;
          while (n % i == 0 ) {
            n = n / i;
          }
          break;
        }
      }
      if (primeCount > 3) break;
    }
    if (primeCount != 3) flag = false;
    if (flag) numberCount++;
  }
  cout << "Ilosc liczb: " << numberCount << endl;
}

int main() {
  ifstream in;
  in.open("liczby.txt");
  for (int i = 0; i < SIZE; i ++) {
    in >> tab[i];
  }
  in.close();
  
  z1();
}
