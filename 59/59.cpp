#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

/* Treœæ
Input: "wyniki_liczby.txt"
1000 ró¿nych liczb od 2 do 9 cyfr
*/

/* Wyniki

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
  int n;
  for (int i = 0; i < SIZE; i++) {
    n = tab[i];
    while (n != 1) {
      n = tab[i]
      
    }
}

int main() {
  ifstream in;
  in.open("wyniki_liczby.txt");
  for (int i = 0; i < SIZE; i ++) {
    in >> tab[i];
  }
  in.close();
  
  z1();
}
