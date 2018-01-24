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
64.1:
Rewersow: 13
Najwieksza ilosc czarnych: 381

64.2:
Liczba obrazkow rekurencyjnych: 60
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000
11111111111111111111
00000000000000000000

64.3:
Liczba poprawnych:171
Liczba naprawialnych: 14
Liczba nienaprawialnych: 15
Najwiecej zlej parzystosci: 7

64.4:
(index, wiersz, kolumna)
(14, 1, 15)
(19, 4, 20)
(26, 21, 13)
(29, 2, 8)
(33, 15, 21)
(115, 21, 14)
(116, 21, 13)
(129, 21, 14)
(131, 10, 7)
(143, 7, 15)
(154, 7, 7)
(161, 21, 17)
(162, 21, 16)
(187, 21, 18)
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

/* Zadanie 1
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

/* Zadanie 2
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

void displayTaskTwo() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout << tab[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

/* Zadanie 3
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
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 21; j++) {
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
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 21; j++) {
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
  if (isCorrect()) return false;
  if (countWrongParityVertical() < 2 && countWrongParityHorizontal() < 2)
    return true;
}

/* Zadanie 4
W obrazku naprawialnym wystarczy zmieniæ jedn¹ wartoœæ, aby uzyskaæ obrazek poprawny.
Dok³adniej, jeœli niepoprawne s¹ bity parzystoœci i-tego wiersza i j-tej kolumny, wystarczy
zmieniæ j-ty piksel w i-tym wierszu. Jeœli niepoprawny jest dok³adnie jeden bit parzystoœci
(wiersza albo kolumny), wystarczy zmieniæ ten bit parzystoœci. 
Podaj numery obrazków naprawialnych, przyjmuj¹c, ¿e numery kolejnych obrazków w pliku
to 1, 2, 3 itd. Przy numerze ka¿dego obrazka naprawialnego podaj numer wiersza i kolumny
wartoœci, któr¹ wystarczy zmieniæ, aby uzyskaæ obrazek poprawny. 
*/

int main() {
  // Zadanie 1
  int rewersCounter = 0, maxBlacks = 0;
  // Zadanie 2
  int recurentCounter = 0;
  bool recurentFlag = true;
  // Zadanie 3
  int correctCounter = 0, repairableCounter = 0, unrepairableCounter = 0, 
      maxWrongParity = 0, wrongParity;
  // Zadanie 4
  int pictureCounter = 0, controlSum, line, column;
  
  for (int n = 0; n < SIZE; n++) {
    readPicture();
    // Zadanie 1
    if (isRewers()) rewersCounter++;
    if (countBlacks() > maxBlacks) maxBlacks = countBlacks();
    
    // Zadanie 2
    if (isRecurent() && recurentFlag) {
      cout << "Obrazek do zadania 2: " << endl;
      displayTaskTwo();
      recurentFlag = false;
      // Pod koniec pêtli zadanie 4
      cout << endl << "Zadanie 4: (index, wiersz, kolumna)" << endl; 
    }
    if (isRecurent()) recurentCounter++;
    
    // Zadanie 3
    if (isCorrect()) correctCounter++;
    else if (isRepairable()) repairableCounter++;
    else unrepairableCounter++;
    wrongParity = countWrongParity();
    if (wrongParity > maxWrongParity) maxWrongParity = wrongParity;
    
    // Zadanie 4
    pictureCounter++;
    if (isRepairable()) {
      column = 0;
      line = 0;
      cout << "(" << pictureCounter << ", ";
      // Sprawdzenie bitu poziomo
      if (countWrongParityHorizontal() == 1) {
        controlSum = 0;
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 21; j++) {
            if (tab[i][j] == '1' && j != 20) controlSum++;
            if (j == 20) {
              if ((controlSum % 2 == 0 && tab[i][j] == '1') ||
                  (controlSum % 2 == 1 && tab[i][j] == '0')) {
                line = i + 1; 
              }
            }
          }
          controlSum = 0;
        }
      }
      // Sprawdzenie bitu pionowo
      if (countWrongParityVertical() == 1) {
        controlSum = 0;
        for (int i = 0; i < 20; i++) {
          for (int j = 0; j < 21; j++) {
            if (tab[j][i] == '1' && j != 20) controlSum++;
            if (j == 20) {
              if ((controlSum % 2 == 0 && tab[j][i] == '1') ||
                  (controlSum % 2 == 1 && tab[j][i] == '0')) {
                column = i + 1; 
              }
            }
          }
          controlSum = 0;
        }
      }
      if (line == 0) line = 21;
      if (column == 0) column = 21;
      cout << line << ", " << column << ")" << endl;
    }
  }
  
  cout << endl << "Zadanie 1:" << endl;
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
