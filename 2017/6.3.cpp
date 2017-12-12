#include<iostream>
#include <iomanip>
#include<fstream>

/* Iloœæ pikseli kotrastuj¹cych (ró¿nica wiêksza ni¿ 128) */

using namespace std;
int main() {
  ifstream inFile;
  inFile.open("dane.txt"); // 753
  // inFile.open("przyklad.txt"); // 5
  int x;
  int i = 0;
  int j = 0;
  int k = 0;
  int tab[200][320];
  
  while (inFile >> tab[i][j]) {
    j++;
    if (j == 320) {
      i++;
      j = 0;
    }
  }
  
  for (i=0; i < 200; i++) {
    for (j=0; j < 320; j++) {
      x = tab[i][j];
      if (i-1 >= 0) {
        if ((x - tab[i-1][j] > 128) || (x - tab[i-1][j] < -128)) {
          k++;
          continue;
        }
      }
      if (i+1 <= 199) {
        if ((x - tab[i+1][j] > 128) || (x - tab[i+1][j] < -128)) {
          k++;
          continue;
        }
      }
      if (j-1 >= 0) {
        if ((x - tab[i][j-1] > 128) || (x - tab[i][j-1] < -128)) {
          k++;
          continue;
        }
      }
      if (j+1 <= 319) {
        if ((x - tab[i][j+1] > 128) || (x - tab[i][j+1] < -128)) {
          k++;
          continue;
        }
      }
    }
  }

  inFile.close();
  cout << k;
  return 0;
}
