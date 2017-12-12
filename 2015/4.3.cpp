#include<iostream>
#include<fstream>

using namespace std;

int main () {
  ifstream file ("liczby.txt"); // 500, 157
  
  string x;
  int k = 0;
  int twocount = 0;
  int eightcount = 0;
  int len;
  
  while (file >> x) {
    len = x.size();
    if (x[len-1] == '0') {
      twocount++;
    }
    if (x[len-1] == '0' && x[len-2] == '0' && x[len-3] == '0') {
      eightcount++;
      cout << x << "\n\n";
    }
  }
  
  cout << "Podzielne przez 2: " << twocount << "\n";
  cout << "Podzielne przez 8: " << eightcount;
  
  return 0;
}
