#include<iostream>
#include <iomanip>
#include<fstream>

/* Otwiera plik i wypisuje min i max */

using namespace std;
int main() {
  ifstream inFile;
  inFile.open("dane.txt"); // 221 i 7
  //inFile.open("przyklad.txt"); // 255 i 0
  
  int x;
  int min = 256;
  int max = 0;
  while (inFile >> x) {
    if (x < min) {
      min = x;
    }
    if (x > max) {
      max = x;
    }
  }
  inFile.close();
  cout << "Max: " << max << " Min: " << min;
  return 0;
}
