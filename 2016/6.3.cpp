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
  ifstream file ("dane_6_3.txt");
  
  string x;
  string y;
  string temp;
  bool okay;
  int n;
  string result = "";
  
  while (file >> x >> y) {
    okay = false;
    for (int i = 0; i < 36; i++) {
      temp = x;
      for (int j = 0; j < x.length(); j++) {
        temp[j] = cipher(x[j], i);
      }
      if (temp == y) {
        okay = true;
      }
    }
    if (okay == false) {
      result = result + x + "\n";
    }
  }
    
  file.close();
  cout << result;
  ofstream wfile ("dane_6_3.txt");
  wfile << result << "\n";
  wfile.close();
  return 0;
}
