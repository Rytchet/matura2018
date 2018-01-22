#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
Input: "ciagi.txt"
Ci¹g liczb ca³kowitych nazywamy ci¹giem arytmetycznym, jeœli ró¿nica miêdzy 
ka¿dymi dwoma kolejnymi jego wyrazami jest identyczna. Ci¹giem arytmetycznym 
jest na przyk³ad ci¹g (1, 3, 5, 7, 9). Jest to ci¹g o ró¿nicy 2, poniewa¿ ka¿dy 
wyraz tego ci¹gu, poza pierwszym, ró¿ni siê od poprzedniego wyrazu o 2. 
Ci¹g (17, 22, 27, 32, 37) jest ci¹giem arytmetycznym o ró¿nicy 5. W tym zadaniu 
rozpatrujemy tylko takie ci¹gi arytmetyczne, które maj¹ dodatni¹ ró¿nicê oraz co
najmniej piêæ wyrazów.
W pliku ciagi.txt danych jest 100 ci¹gów sk³adaj¹cych siê z liczb ca³kowitych 
dodatnich, nieprzekraczaj¹cych 1 000 000. Ka¿dy ci¹g opisany jest w dwóch 
wierszach: pierwszy zawiera liczbê wyrazów ci¹gu (co najmniej 5 i co 
najwy¿ej 1000), zaœ drugi — kolejne wyrazy ci¹gu, oddzielone pojedynczymi 
odstêpami. Dla przyk³adu pierwsze cztery wiersze pliku maj¹ nastêpuj¹c¹ postaæ:
5
1 3 6 7 9
5
17 22 27 32 37 
*/

/* Wyniki
61.1:
Liczba ci¹gów: 44
Najwiêksza ró¿nica: 246849
61.2:
1
27
551368
1000000
250047
1000
35937
531441
*/

const int SIZE = 100;

/*
Podaj, ile spoœród podanych w pliku ciagi.txt ci¹gów jest ci¹gami 
arytmetycznymi. ZnajdŸ wœród nich ci¹g o najwiêkszej ró¿nicy i oblicz jego 
ró¿nicê. Liczbê ci¹gów arytmetycznych oraz najwiêksz¹ ró¿nicê zapisz w pliku 
wynik1.txt. 
*/

void z1() {
  cout << "Zadanie 1:" << endl;
  ifstream in("ciagi.txt");
  int tab[1000];
  int length, difference;
  int counter = 0, max = 0;
  bool flag;
  for (int i = 0; i < SIZE; i++) {
    flag = true;
    in >> length;
    for (int j = 0; j < length; j++) in >> tab[j];
    difference = tab[1] - tab[0];
    for (int j = 1; j < length; j++) {
      if (tab[j] - tab[j - 1] != difference) flag = false;
    }
    if (flag) {
      counter++;
      if (difference > max) max = difference;
    }
  }
  in.close();
  ofstream out("wynik1.txt");
  out << "Liczba ciagow: " << counter << "\n";
  cout << "Liczba ciagow: " << counter << "\n";
  out << "Najwieksza roznica: " << max << "\n";
  cout << "Najwieksza roznica: " << max << "\n";
  out.close();
}

/*
Dla ka¿dego podanego ci¹gu znajdŸ — jeœli istnieje — najwiêksz¹ wystêpuj¹c¹ w 
nim liczbê, która jest pe³nym szeœcianem jakiejœ liczby naturalnej (w pierwszym 
z przyk³adowych ci¹gów jest to 1 = 1^3 , w drugim — 27 = 3^3).
Znalezione liczby (po jednej dla ka¿dego ci¹gu, w którym taka liczba wystêpuje) 
zapisz w pliku wynik2.txt, w kolejnoœci zgodnej z kolejnoœci¹ ci¹gów, z których 
pochodz¹
*/

void z2() {
  cout << "Zadanie 2:" << endl;
  ifstream in("ciagi.txt");
  ofstream out("wynik2.txt", ios::app);
  int tab[1000];
  int length, max;
  bool flag;
  for (int i = 0; i < SIZE; i++) {
    in >> length;
    for (int j = 0; j < length; j++) in >> tab[j];
    max = 0;
    flag = false;
    for (int j = 0; j < length; j++) {
      for (int k = 1; k <= tab[j]; k++) {
        if (k * k * k == tab[j]) {
          if (tab[j] > max) max = tab[j];
          break;
        }
      }
    }
    if (max > 0) {
      cout << max << endl;
      out << max << endl;
    }
  }
  in.close();
  out.close();
}

/*
Plik bledne.txt ma identyczn¹ strukturê jak ciagi.txt, ale zawiera tylko 20 
ci¹gów. Wiadomo jednak, ¿e wszystkie wystêpuj¹ce w nim ci¹gi s¹ ci¹gami 
arytmetycznymi z jednym b³êdem: jeden z wyrazów w ka¿dym ci¹gu zosta³ zast¹piony
przez liczbê naturaln¹ nienale¿¹c¹ do ci¹gu.
Dla ka¿dego ci¹gu znajdŸ i wypisz b³êdny wyraz. Odpowiedzi zapisz w pliku 
wynik3.txt, podaj¹c dla ka¿dego ci¹gu b³êdn¹ liczbê w osobnym wierszu, w 
kolejnoœci zgodnej z kolejnoœci¹ ci¹gów w pliku wejœciowym. 
*/

void z3() {
  cout << "Zadanie 3:" << endl;
  ifstream in("bledne.txt");
  ofstream out("wynik3.txt", ios::app);
  int tab[1000];
  int length, difference, badNumber;
  for (int i = 0; i < 20; i++) {
    in >> length;
    for (int j = 0; j < length; j++) in >> tab[j];
    
    if (tab[1] - tab[0] == tab[2] - tab[1]) difference = tab[1] - tab[0];
    else difference = tab[4] - tab[3];
    
    if (tab[1] - tab[0] != difference && tab[2] - tab[1] == difference)
      badNumber = tab[0];
    else {
      for (int j = 1; j < length; j++)
        if (tab[j] - tab[j - 1] != difference) badNumber = tab[j];
    }
    
    cout << badNumber << endl;
    out << badNumber << endl;
  }
  in.close();
  out.close();
}

int main() {
  z1();
  z2();
  z3();
}
