#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<math.h>

using namespace std;

double policz(int k);

int main() {
  double pi = M_PI;
  
  double x, e;
  
  for (int i = 0; i < 1700; i++) {
    x = policz(i);
    e = abs(pi - x);
    cout << e << "\n";
  }
  
  return 0;
}

double policz(int k) {
  ifstream file;
  file.open("punkty.txt");
  
  int r = 200;
  int a = 200;
  int b = 200;
  
  double nk = 0;
  double n = 0; 
  
  int x, y;
  int count = 0;

  while (file >> x >> y && count++ <= k) {
    if (x >= 0 && x <= 400 && y >= 0 && y <= 400) {
      n++;
    }
    if ((x-a)*(x-a) + (y-b)*(y-b) <= r*r) {
      nk++;
    }
  }
  double p = 400*400;
  //cout<< "p: " << p << " n: " << n << " nk: " << nk << "\n";
  double pk = (nk / n) * p;
  //cout << "pk: " << pk << "\n";
  double pi = pk / (r * r);
  
  cout << "pi dla pierwszych " << k+1 << " punktow: " << pi << "\n";
  return pi;
}
