#include<iostream>
#include<fstream>

using namespace std;

char cipher(char x, int n) {
  x = (int) x;
  
  for (int i = 0; i < n; i++) {
    if (x == 90) {
      x = 65;
      continue;
    }
    x++;
  }
  x = (char) x;
  return x;
}

int main() {
  ifstream file ("dane_6_1.txt");
  
  string x;
  string result = "";
  
  while (file >> x) {
    for (int i = 0; i < x.length(); i++) {
      x[i] = cipher(x[i], 107);
    }
    result = result + x + "\n";
    cout << x << "\n";
  }
  file.close();
  ofstream wfile ("dane_6_1.txt");
  wfile << result << "\n";
  wfile.close();
  return 0;
}
