#include <iostream>
#include <fstream>
using namespace std;
// Czeœæ Dominisia
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
64.1: 13, 381

64.2: 60,
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/

const int SIZE = 200;
ifstream in("dane_obrazki.txt");
char tab[21][21];

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

/*
Obrazek nazywamy rewersem, jeœli liczba wystêpuj¹cych w nim pikseli czarnych jest wiêksza
od liczby pikseli bia³ych.
Przyk³ad: W obrazku z powy¿szego przyk³adu wystêpuje 18 pikseli czarnych i 7 pikseli
bia³ych. Zatem jest on rewersem.
Podaj, ile jest w pliku obrazków, które s¹ rewersami. Podaj te¿ najwiêksz¹ liczbê pikseli czarnych
wystêpuj¹cych w jednym obrazku. 
*/

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

int countBlacks() {
  int counter = 0;
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (tab[i][j] == '1') counter++;
    }
  }
  return counter;
}

/*
Obrazek rozmiaru n × n bêdziemy nazywaæ rekurencyjnym, jeœli n jest parzyste oraz obrazek
sk³ada siê z 4 kopii tego samego obrazka rozmiaru n/2 * n/2.
Podaj liczbê obrazków rekurencyjnych w pliku wejœciowym. Ponadto podaj opis pierwszego
obrazka rekurencyjnego wystêpuj¹cego w pliku. W opisie obrazka pomiñ bity parzystoœci.
*/

bool isRecurent() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (tab[i][j] != tab[i][j + 10] || tab[i][j] != tab[i + 10][j] || 
          tab[i][j] != tab[i+10][j+10]) {
        return false;
      }
    }
  }
  return true;
}

void displayPictureWithoutParity() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout << tab[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

/*
Obrazek nazywamy poprawnym, jeœli wszystkie bity parzystoœci s¹ w nim poprawne (zarówno
w wierszach, jak i kolumnach). Obrazek nazywamy naprawialnym, jeœli nie jest poprawny,
a jednoczeœnie co najwy¿ej jeden bit parzystoœci wiersza i co najwy¿ej jeden bit parzystoœci
kolumny jest w nim niepoprawny.
Natomiast nienaprawialnym nazywamy obrazek, który nie jest poprawny i nie jest naprawialny. 
Podaj liczbê obrazków poprawnych, liczbê obrazków naprawialnych oraz liczbê obrazków
nienaprawialnych. Ponadto podaj najwiêksz¹ liczbê b³êdnych bitów parzystoœci wystêpuj¹-
cych w jednym obrazku.
Bit parzystoœci ci¹gu z³o¿onego z zer i jedynek jest równy 0, gdy w ci¹gu tym wystêpuje parzysta
liczba jedynek, w przeciwnym razie bit parzystoœci jest równy 1.
*/

int countWrongParityHorizontal() {
  int sum = 0, counter = 0;
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (i == 21 && j == 21) continue;
      if (tab[i][j] == '1' && j != 20) sum++;
      if (j == 20) {
        if (sum % 2 == 0 && tab[i][j] == '1') counter++;
        if (sum % 2 == 1 && tab[i][j] == '0') counter++; 
      }
    }
    sum = 0;
  }
  return counter;
}

int countWrongParityVertical() {
  int sum = 0, counter = 0;
  for (int i = 0; i < 21; i++) {
    for (int j = 0; j < 21; j++) {
      if (i == 21 && j == 21) continue;
      if (tab[j][i] == '1' && j != 20) sum++;
      if (j == 20) {
        if (sum % 2 == 0 && tab[j][i] == '1') counter++;
        if (sum % 2 == 1 && tab[j][i] == '0') counter++; 
      }
    }
    sum = 0;
  }
  return counter;
}

int countWrongParity() {
  return countWrongParityHorizontal() + countWrongParityVertical();
}

bool isCorrect () {
  if (countWrongParity() == 0) return true;
}

bool isRepairable() {
  if (countWrongParityVertical() < 2 && countWrongParityHorizontal() < 2)
    return true;
}

int main() {
  // Zadanie 1
  int rewersCounter = 0, maxBlacks = 0;
  // Zadanie 2
  int recurentCounter = 0;
  bool recurentFlag = true;
  // Zadanie 3
  int correctCounter = 0, repairableCounter = 0, unrepairableCounter = 0, 
      maxWrongParity = 0, wrongParity;
  
  for (int i = 0; i < SIZE; i++) {
    readPicture();
    // Zadanie 1
    if (isRewers()) rewersCounter++;
    if (countBlacks() > maxBlacks) maxBlacks = countBlacks();
    
    // Zadanie 2
    if (isRecurent() && recurentFlag) {
      cout << "Obrazek do zadania 2: " << endl;
      displayPictureWithoutParity();
      recurentFlag = false;
    }
    if (isRecurent()) recurentCounter++;
    
    // Zadanie 3
    if (isCorrect()) correctCounter++;
    else if (isRepairable()) repairableCounter++;
    else unrepairableCounter++;
    wrongParity = countWrongParity();
    if (wrongParity > maxWrongParity) maxWrongParity = wrongParity;
  }
  
  cout << "Zadanie 1:" << endl;
  cout << "Rewersow: " << rewersCounter << endl;
  cout << "Najwieksza ilosc czarnych: " << maxBlacks << endl << endl;
  
  cout << "Zadanie 2:" << endl;
  cout << "Liczba obrazkow rekurencyjnych: " << recurentCounter << endl << endl;
  
  cout << "Zadanie 3:" << endl;
  cout << "Liczba poprawnych:" << correctCounter << endl;
  cout << "Liczba naprawialnych: " << repairableCounter << endl;
  cout << "Liczba nienaprawialnych: " << unrepairableCounter << endl;
  cout << "Najwiecej zlej parzystosci: " << maxWrongParity << endl << endl;
  
}
