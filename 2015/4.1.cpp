#include<iostream>
#include<fstream>

using namespace std;

int main () {
  ifstream file ("liczby.txt"); // 422
  
  string x;
  int k = 0;
  int zerocount;
  int onecount;
  
  while (file >> x) {
    zerocount = 0;
    onecount = 0;
    for (int i =0; i < x.length(); i++) {
      if (x[i] == '0')
        zerocount++;
      else
        onecount ++;
    }
    if (zerocount > onecount) {
      k++;
    }
  }
  
  cout << k;
  
  return 0;
}
