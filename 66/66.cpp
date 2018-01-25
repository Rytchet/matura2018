#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
W pliku trojki.txt w oddzielnych wierszach znajduje siê 1000 trójek liczb naturalnych
z przedzia³u od 1 do 550000000. W ka¿dym wierszu s¹ umieszczone trzy liczby rozdzielone
pojedynczymi odstêpami. 
Przyk³ad
3 4 5
12 5 13
12 491 17
11 13 143
15 28 91 
*/

/* Wyniki
66.1:

*/

const int SIZE = 1000;

/* Zadanie 1
Wypisz wszystkie trójki liczb z pliku trojki.txt, w których suma cyfr dwóch pierwszych
liczb jest równa ostatniej (trzeciej) liczbie. 
*/

sumOfDigits(int n) {
  int sum = 0;
  while (n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("trojki.txt");
  int a, b, c;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b >> c;
    if (sumOfDigits(a) + sumOfDigits(b) == c) {
      cout << a << " " << b << " " << c << endl;
    }
  }
  in.close();
}

int main() {
  z1();
}
