#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
Input: "liczby.txt"
1000 ró¿nych liczb od 2 do 9 cyfr
*/

/* Wyniki
59.1: 114
59.2: 181
59.3:
Min: 11
Max: 999342708
1: 381, 2: 344, 3: 171, 4: 76, 5: 22, 6: 4, 7: 0, 8: 2
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
  cout << numberCount << endl;
}

/*
Podaj, ile jest w pliku liczby.txt liczb, dla których suma danej liczby i 
liczby odwróconej jest liczb¹ palindromiczn¹, tzn. jej zapis dziesiêtny 
jest palindromem. 
*/

int reverse(int n) {
  int result = 0;
  while (n > 0) {
    result = 10 * result + n % 10;
    n = n / 10;
  }
  return result;
}

void z2() {
  cout << "Zadanie 2: " << endl;
  int counter = 0;
  int result;
  for (int i = 0; i < SIZE; i++) {
    result = tab[i] + reverse(tab[i]);
    if (reverse(result) == result) counter++;
  }
  cout << counter << endl;
}

/*
Niech w(n) oznacza iloczyn cyfr liczby n. Dla danej liczby n tworzymy ci¹g, 
w którym kolejny element jest iloczynem cyfr wystêpuj¹cych w poprzednim 
elemencie. Ci¹g koñczy siê, gdy liczba jest liczb¹ jednocyfrow¹. Wówczas moc¹ 
liczby n jest liczba k. 
Podaj, ile jest w pliku liczby.txt liczb o mocy 1, 2, 3, ..., 8. 
Dodatkowo podaj minimaln¹ i maksymaln¹ liczbê o mocy równej 1. 

Przyk³ad:
Liczba 678 ma moc 4, poniewa¿:
6 * 7 * 8 = 336
3 * 3 * 6 = 54
5 * 4 = 20
2 * 0 = 0
Liczba 1991 ma moc 2, poniewa¿
1 * 9 * 9 * 1 = 81
8 * 1 = 8 
*/

int w(int n) {
  int product = 1;
  int number;
  while (n > 0) {
    number = n % 10;
    n = n / 10;
    product = product * number;
  }
  return product;
}

void z3() {
  cout << "Zadanie 3: " << endl;
  int k, product;
  int result[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
  int min = 999999, max = 0;
  for (int i = 0; i < SIZE; i++) {
    k = 0;
    product = tab[i];
    do {
      product = w(product);
      k++;
    } while (product > 9);
    if (k < 9) {
      result[k] = result[k] + 1;
    }
    if (k == 1) {
      if (tab[i] > max) max = tab[i];
      if (tab[i] < min) min = tab[i];
    }
  }
  cout << "Minimum k = 1: " << min << endl;
  cout << "Maksimum k = 1: " << max << endl;
  for (int i = 1; i < 9; i++) {
    cout << i << ": " << result[i] << "; ";
  }
  cout << endl;
}

int main() {
  ifstream in;
  in.open("liczby.txt");
  for (int i = 0; i < SIZE; i ++) {
    in >> tab[i];
  }
  in.close();
  
  z1();
  z2();
  z3();
}
