#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

/* Treœæ
Input: "liczby.txt"
200 ró¿nych liczb ca³kowitych z przedzia³u [2, 1 000 000]
*/

/* Wyniki
6.1: 12, Ostatnie dwie 540, 633
6.2: 
*/

const int SIZE = 200;
int tab[SIZE];

/*
Policz, ile jest w pliku wejœciowym liczb mniejszych ni¿ 1000, oraz podaj dwie 
takie liczby, które pojawiaj¹ siê w pliku jako ostatnie (mo¿esz za³o¿yæ, ¿e 
bêd¹ co najmniej dwie). 
*/

void z1() {
  cout << "Zadanie 1: " << endl;
  int counter = 0;
  int lastNumber, lastNumber2;
  for (int i = 0; i < SIZE; i++) {
    if (tab[i] < 1000) {
      counter++;
      lastNumber = lastNumber2;
      lastNumber2 = tab[i];
    }
  }
  cout << "Liczb mniejszych od 1000: " << counter << endl;
  cout << "Ostatnie dwie: " << lastNumber << ", " << lastNumber2 << endl;
}

/*
Wœród liczb wystêpuj¹cych w pliku wejœciowym znajdŸ te, które maj¹ dok³adnie 18 
dzielników naturalnych (wliczaj¹c w nie 1 i sam¹ liczbê). Dla ka¿dej znalezionej 
liczby wypisz, oprócz jej wartoœci, listê wszystkich jej dzielników, posortowan¹ 
rosn¹co
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  int counter;
  int dividers[18];
  for (int i = 0; i < SIZE; i++) {
    counter = 0;
    for (int j = 1; j <= tab[i]; j++) {
      if (tab[i] % j == 0) {
        dividers[counter] = j;
        counter++;
      }
      if (counter > 18) break;
    }
    if (counter == 18) {
      sort(dividers, dividers + 18);
      cout << "Liczba: " << tab[i] << endl;
      for (int j = 0; j < 18; j++) cout << dividers[j] << " ";
      cout << endl;
    }
  }
}

int main() {
  ifstream in;
  in.open("liczby.txt");
  for (int i = 0; i < SIZE; i++) {
    in >> tab[i];
  }
  in.close();
  
  z1();
  z2();
}
