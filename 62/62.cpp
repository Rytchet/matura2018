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
62.3:
a) 160
b) 357
62.4: (prawdopodobnie b³¹d w odpowiedziach, wyniki s¹ zamienione miejscami)
411
625
*/

const int SIZE = 1000;

/*
Wyszukaj w pliku liczby1.txt dwie liczby, najmniejsz¹ i najwiêksz¹. Podaj wartoœci
tych liczb w zapisie ósemkowym.
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("liczby1.txt");
  int tab[SIZE];
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  int min = 9999999;
  int max = 0;
  for (int i = 0; i < SIZE; i++) {
    if (tab[i] < min) min = tab[i];
    if (tab[i] > max) max = tab[i];
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
  int tab[SIZE];
  ifstream in("liczby2.txt");
  for (int i = 0; i < 1000; i++) in >> tab[i];
  in.close();
  int counter = 0, maxCounter = 0, firstNumber = 0;
  int maxFirst;
  for (int i = 1; i < SIZE; i++) {
    if (tab[i] >= tab[i - 1]) {
      counter++;
      if (firstNumber == 0) {
        firstNumber = tab[i - 1];
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

/*
Porównaj wartoœci liczb zapisanych w wierszach o tych samych numerach w plikach liczby1.txt
i liczby2.txt. Podaj liczbê wierszy, w których:
a) liczby maj¹ w obu plikach tak¹ sam¹ wartoœæ;
b) wartoœæ liczby z pliku liczby1.txt jest wiêksza od wartoœci liczby z pliku liczby2.txt.

Dla przyk³adowych danych:
liczby1.txt liczby2.txt
11456       1302
22666       9654
546         499
odp. a) 1 wiersz, bo tylko w drugim wierszu liczby maj¹ tak¹ sam¹ wartoœæ: 22666(8) = 9654(10)
odp. b) 1 wiersz, bo tylko w pierwszym wierszu wartoœæ liczby w pierwszym pliku jest wiêksza
ni¿ odpowiadaj¹ca jej wartoœæ w drugim pliku: 11456(8)>1302(10). 
*/

void z3() {
  cout << "Zadanie 3:" << endl;
  int tab1[SIZE], tab2[SIZE];
  ifstream in1("liczby1.txt");
  ifstream in2("liczby2.txt");
  for (int i = 0; i < SIZE; i++) in1 >> oct >> tab1[i];
  for (int i = 0; i < SIZE; i++) in2 >> tab2[i];
  in1.close();
  in2.close();
  int aCounter = 0, bCounter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (tab1[i] == tab2[i]) aCounter++;
    if (tab1[i] > tab2[i]) bCounter++;
  }
  cout << "a) " <<  aCounter << endl << "b) " << bCounter << endl;
}

/*
Podaj, ile razy w zapisie dziesiêtnym wszystkich liczb z pliku liczby2.txt wystêpuje
cyfra 6 oraz ile razy wyst¹pi³aby ta cyfra, gdyby te same liczby by³y zapisane w systemie
ósemkowym.
*/

void z4() {
  cout << "Zadanie 4:" << endl;
  ifstream in("liczby2.txt");
  int tab[SIZE];
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  int firstCounter = 0, secondCounter = 0;
  int number;
  for (int i = 0; i < SIZE; i++) {
    number = tab[i];
    while (number) {
      if (number % 10 == 6) firstCounter++;
      number = number / 10;
    }
    number = tab[i];
    while (number) {
      if (number % 8 == 6) secondCounter++;
      number = number / 8;
    }
  }
  cout << firstCounter << " " << secondCounter << endl;
}

int main() {
  z1();
  z2();
  z3();
  z4();
}
