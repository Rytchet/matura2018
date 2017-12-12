#include<iostream>
#include <iomanip>
#include<fstream>

/* Najd³u¿sza linia pionowa tych samych pikseli */

using namespace std;
int main() {
  ifstream inFile;
  inFile.open("dane.txt"); // 5
  // inFile.open("przyklad.txt"); // 198

  int i = 0;
  int j = 0;
  int tab[200][320];
  
  while (inFile >> tab[i][j]) {
    j++;
    if (j == 320) {
      i++;
      j = 0;
    }
  }
  
  int k = 0;
  int now;
  int prev;
  int max = 0;
  
  for (j = 0; j < 320; j++) {
    for (i = 0; i < 200; i++) {
      if (i == 0) {
        k = 0;
        now = tab[i][j];
        k++;
        continue;
      }
      prev = now;
      now = tab[i][j];
      if (now == prev) {
        k++;
      }
      else {
        k = 1;
      }
      if (k > max) {
        max = k;
      }
    }
  }
  
  inFile.close();
  cout << max;
  return 0;
}
