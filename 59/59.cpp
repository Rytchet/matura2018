#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;

/* Tre��
Input: "wyniki_liczby.txt"
1000 r�nych liczb od 2 do 9 cyfr
*/

/* Wyniki

*/

const int SIZE = 1000;
string Stab[SIZE];
int Itab[SIZE];

/*
Czynnikiem pierwszym danej liczby naturalnej z�o�onej jest dowolna liczba 
pierwsza, kt�ra dzieli t� liczb� ca�kowicie. Podaj, ile jest w pliku liczby.txt 
liczb, w kt�rych rozk�adzie na czynniki pierwsze wyst�puj� dok�adnie trzy r�ne 
czynniki (mog� si� one powtarza�), z kt�rych ka�dy jest nieparzysty.
*/
void z1() {
  
}

int main() {
  ifstream in;
  in.open("wyniki_liczby.txt");
  string a;
  for (int i = 0; i < SIZE; i ++) {
    in >> a;
    Stab[i] = a;
    Itab[i] = atoi(a)
  }
  
  in.close();
}
