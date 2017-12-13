#include <fstream>
#include <iostream>
#include <cmath>
#define toDigit(c) (c-'0')
using namespace std;

/* Treœæ
Input: 3 pliki - "dane_systemy$.txt"
W ka¿dym pliku zastosowany inny system liczbowy: 1 - base2; 2 - base4; 3 - base8
W pierwszej kolumnie podana godzina, w drugiej zanotowana temperatura stacji
We wszystkich plikach 3*365 = 1095 wierszy
*/

/* Wyniki
58.1.1: -1011
58.1.2: -1001100
58.1.3: -1001011
58.2: 182
58.3: 42
58.4: 25
*/

int convertToDec(string number, int base);
string convertToBin(int number);

// Piotr stêpieñ

const int SIZE = 1095;
int time1[SIZE], time2[SIZE], time3[SIZE];
int temp1[SIZE], temp2[SIZE], temp3[SIZE];


/*
Dla ka¿dej stacji pogodowej podaj najni¿sz¹ zarejestrowan¹ temperaturê, 
a wszystkie wyniki zapisz w systemie binarnym (dwójkowym). 
*/
void z1() {
  cout << endl << "Zadanie 1:" << endl;
  int min1 = temp1[0], min2 = temp1[0], min3 = temp1[0];
  for (int i = 1; i < SIZE; i++) {
    if (temp1[i] < min1) min1 = temp1[i];
    if (temp2[i] < min2) min2 = temp2[i];
    if (temp3[i] < min3) min3 = temp3[i];
  }
  cout << "Pierwsza stacja: " << convertToBin(min1) << endl;
  cout << "Druga stacja: " << convertToBin(min2) << endl;
  cout << "Trzecia stacja: " << convertToBin(min3) << endl;
}

/*
Zgodnie z harmonogramem pomiary wykonywane s¹ co 24 godziny, pocz¹wszy od 
pierwszego pomiaru. Oznacza to, ¿e wyra¿one dziesiêtnie stany zegarów 
kolejnych pomiarach powinny wynosiæ 12, 12+24=36, 12+2·24=60 itd.
Podaj liczbê pomiarów, w których zarejestrowany stan zegara by³ niepoprawny 
jednoczeœnie we wszystkich stacjach pogodowych. 
*/
void z2() {
  cout << endl << "Zadanie 2: " << endl;
  int time = 12, count = 0;
  for (int i = 0; i < SIZE; i++) {
    if (time1[i] != time && time2[i] != time && time3[i] != time) count++;
    time += 24;
  }
  cout << "Ilosc blednych wskazan zegara: " << count << endl;
}

/*
Rekordem temperatury dla danej stacji pogodowej nazywaæ bêdziemy pomiar 
temperatury, który jest wiêkszy od wszystkich wczeœniejszych pomiarów dokonanych 
w tej stacji. Dniem rekordowym jest dzieñ, w którym w co najmniej jednej stacji 
pogodowej zarejestrowano rekord temperatury. Podaj liczbê dni rekordowych.
*/
void z3() {
  cout << endl << "Zadanie 3:" << endl;
  int min1 = temp1[0], min2 = temp2[0], min3 = temp3[0];
  int count = 1;
  bool flag;
  for (int i = 1; i < SIZE; i++) {
    flag = false;
    if (temp1[i] > min1) { 
      min1 = temp1[i];
      flag = true;
    }
    if (temp2[i] > min2) { 
      min2 = temp2[i];
      flag = true;
    }
    if (temp3[i] > min3) { 
      min3 = temp3[i];
      flag = true;
    }
    if (flag) count++;
  }
  cout << "Ilosc rekordowych dni: " << count << endl;
}

/*
Oznaczmy kolejne zarejestrowane temperatury w stacji pogodowej S1 
przez t1, t2, t3,… Niech rij oznacza kwadrat ró¿nicy miêdzy temperaturami 
w i-tym i j-tym pomiarze pierwszej stacji pogodowej, rij=(ti – tj)^2. 
Skokiem temperatury miêdzy i-tym a j-tym pomiarem nazywaæ bêdziemy zaokr¹glenie 
w górê do liczby ca³kowitej u³amka rij / |i – j|. Podaj najwiêkszy skok 
temperatury w stacji pogodowej S1. Wynik podaj w systemie dziesiêtnym.
*/
void z4() {
  cout << endl << "Zadanie 4: " << endl;
  float rij;
  float jump;
  int max = 0;
  for (int i = 0; i < SIZE - 1; i++) {
    for (int j = i + 1; j < SIZE; j++) {
      rij = (temp1[i] - temp1[j]) * (temp1[i] - temp1[j]);
      jump = rij / abs(i - j);
      jump = ceil(jump);
      if (jump > max) max = jump;
    }
  }
  cout << "Najwiekszy skok: " << max << endl;
}

int main() {
  ifstream in1, in2, in3;
  in1.open("dane_systemy1.txt");
  in2.open("dane_systemy2.txt");
  in3.open("dane_systemy3.txt");
  string a, b;
  for (int i = 0; i < SIZE; i++) {
    in1 >> a >> b;
    time1[i] = convertToDec(a, 2);
    temp1[i] = convertToDec(b, 2);
    in2 >> a >> b;
    time2[i] = convertToDec(a, 4);
    temp2[i] = convertToDec(b, 4); 
    in3 >> a >> b;
    time3[i] = convertToDec(a, 8);
    temp3[i] = convertToDec(b, 8); 
  }
  z1();
  z2();
  z3();
  z4();
  
  in1.close();
  in2.close();
  in3.close();
  return 0;
}

int convertToDec(string number, int base) {
  long result = 0;
  int sign = 1;
  if (number[0] == '-') {
    sign = -1;
    number = number.substr(1);
  }
  long j = 1;
  for (int i = (number.length() - 1); i >= 0; i--) {
    result += toDigit(number[i]) * j;
    j *= base;
  }
  return sign * result;
}

string convertToBin(int number) {
  int j = 2;
  string ans = "";
  string tmp = "";
  if (number < 0) {
    tmp = "-";
    number = -number;
  }
  while (number > 0) {
    if (number % j != 0) {
      ans += "1";
      number -= j / 2;
    }
    else {
      ans += "0";
    }
    j = j*2;
  }
  // Odwróæ ans
  for (int i = (ans.length() - 1); i >= 0; i--) {
    tmp += ans[i];
  }
  return tmp;
}
