#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
Bit parzystoœci ci¹gu z³o¿onego z zer i jedynek jest równy 0, gdy w ci¹gu tym wystêpuje parzysta
liczba jedynek, w przeciwnym razie bit parzystoœci jest równy 1.
Czarno-bia³y obrazek rozmiaru n × n sk³ada siê z n wierszy po n pikseli. Ka¿dy wiersz pikseli
reprezentujemy jako ci¹g zer i jedynek, ka¿dy bia³y piksel reprezentujemy przez 0, czarny —
przez 1. Na koñcu ka¿dego wiersza dodany jest bit parzystoœci, podobnie pod ostatnim wierszem
obrazka do³¹czony jest wiersz bitów parzystoœci ka¿dej z n kolumn. Bitów parzystoœci
nie traktujemy jako czêœci obrazka.
Plik dane_obrazki.txt sk³ada siê z opisu 200 czarno-bia³ych obrazków o rozmiarze
20 × 20 pikseli. S¹siednie obrazki oddzielone s¹ w pliku pustym wierszem.
*/

/* Wyniki

*/

const int SIZE = 200;
ifstream in("dane_obrazki.txt");
char tab[21][21];

/*
Obrazek nazywamy rewersem, jeœli liczba wystêpuj¹cych w nim pikseli czarnych jest wiêksza
od liczby pikseli bia³ych.
Przyk³ad: W obrazku z powy¿szego przyk³adu wystêpuje 18 pikseli czarnych i 7 pikseli
bia³ych. Zatem jest on rewersem.
Podaj, ile jest w pliku obrazków, które s¹ rewersami. Podaj te¿ najwiêksz¹ liczbê pikseli czarnych
wystêpuj¹cych w jednym obrazku. 
*/

void readPicture() {
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (i == 20 && j == 20) return;
      in >> tab[i][j];
    }
  }
}

void displayPicture() {
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      cout << tab[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool isRewers() {
  int black = 0, white = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (tab[i][j] == '0') white++;
      if (tab[i][j] == '1') black++;
    }
  }
  return black > white;
}

int main() {
  int rewersCounter = 0;
  
  for (int i = 0; i < SIZE; i++) {
    readPicture();
    if (isRewers()) rewersCounter++;
  }
  
  cout << "Zadanie 1:" << endl;
  cout << "Rewersow: " << rewersCounter << endl;
}





