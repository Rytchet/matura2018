#include<iostream>
#include <iomanip>
#include<fstream>

/* Ile wierszy nale¿y usun¹æ do pionowej osi symetrii */

using namespace std;
int main() {
  ifstream inFile;
  inFile.open("dane.txt"); // 149
  //inFile.open("przyklad.txt"); // 3
  int x;
  int i = 0;
  int k = 0;
  int tab[320];
  bool action = true;
  
  while (inFile >> tab[i]) {
    action = true;
    if (i == 319) {
      i = 0;
      for (; i < 160; i++) {
        if (tab[i] != tab[319-i]) {
          k++;
          break;
        }
      }
      i = 0;
      action = false;
    }
    if (action) {
      i++;
    }
  }
  
  inFile.close();
  cout << k;
  return 0;
}
