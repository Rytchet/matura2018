#include<iostream>
#include<fstream>

using namespace std;

char decipher(char x, int n) {
  x = (int) x;
  
  for (int i = 0; i < n; i++) {
    if (x == 65) {
      x = 90;
      continue;
    }
    x--;
  }
  x = (char) x;
  return x;
}

int main() {
  ifstream file ("dane_6_2.txt");
  
  string x;
  int n;
  string result = "";
  
  while (file >> x >> n) {
    for (int i = 0; i < x.length(); i++) {
      x[i] = decipher(x[i], n);
    }
    result = result + x + "\n";
    cout << x << "\n";
  }
  file.close();
  ofstream wfile ("dane_6_2.txt");
  wfile << result << "\n";
  wfile.close();
  return 0;
}
