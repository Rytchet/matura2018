#include<iostream>
#include<fstream>
#include<cmath>
#include<string>

using namespace std;

int main() {
  ifstream file;
  file.open("punkty.txt"); // 7852
  
  int r = 200;
  int a = 200;
  int b = 200;
  
  int x, y;
  int k = 0;
  int count = 0;
  string coords = "";
  
  while (file >> x >> y) {
    if ((x-a)*(x-a) + (y-b)*(y-b) < r*r) {
      k++;
    }
    if ((x-a)*(x-a) + (y-b)*(y-b) == r*r) {
      cout << "[" << x << ", " << y << "] ";
    }
  }
  
  cout << k << "\n" + coords;
  return 0;
}
