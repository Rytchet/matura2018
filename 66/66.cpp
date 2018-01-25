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
25320 29269 40
24810 10353 27
15276 20113 28
13867 24491 45
19677 6037 46
19688 2020 36

66.2:
6131 20807 127567717
26297 6329 166433713
24767 809 20036503
28477 19289 549292853
24799 6359 157696841
691 11003 7603073
9631 28351 273048481
6661 26393 175803773
5881 28429 167190949
18587 21739 404062793
*/

const int SIZE = 1000;

void display(int a, int b, int c) {
  cout << a << " " << b << " " << c << endl;
}

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
    if (sumOfDigits(a) + sumOfDigits(b) == c) display(a, b, c);
  }
  in.close();
  cout << endl;
}

/*
Wypisz wszystkie wiersze z pliku trojki.txt zawieraj¹ce takie trzy liczby a, b, c, w któ-
rych a i b s¹ liczbami pierwszymi oraz c = a · b. 
*/

bool isPrime(int n) {
  if (n <= 1) return false;
  if (n % 2 == 0 && n!= 2) return false;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

void z2() {
  cout << "Zadanie 2:" << endl;
  ifstream in("trojki.txt");
  int a, b, c;
  for (int i = 0; i < SIZE; i++) {
    in >> a >> b >> c;
    if (isPrime(a) && isPrime(b) && a * b == c) display(a, b, c);
  }
  in.close();
  cout << endl;
}

int main() {
  z1();
  z2();
}
