#include <iostream>
#include <fstream>
using namespace std;

/* Tre��
Informacj� genetyczn� (genotyp) ka�dego osobnika z galaktyki Madgen opisuje s�owo (napis),
w kt�rym wyst�puj� litery ze zbioru {A, B, C, D, E}. Obowi�zuj� przy tym nast�puj�ce
zasady:
1. Organizmy �yj�ce na Madgen tworz� gatunki g1, g2, g3, �, gdzie gi to zbi�r osobnik�w
  o d�ugo�ci genotypu r�wnej i.
2. W sk�ad genotypu mog� wchodzi� geny. Pierwszy gen rozpoczyna si� pierwsz� wyst�puj�c�
  w genotypie sekwencj� AA, a ko�czy si� najbli�sz� napotkan� po niej sekwencj�
  BB. Ka�dy kolejny gen rozpoczyna si� pierwsz� sekwencj� AA, wyst�puj�c�
  za ko�cem poprzedniego genu, i analogicznie ko�czy si� najbli�sz� napotkan� sekwencj� BB.
3. Geny nazywamy cz�ci� koduj�c� genotypu, pozosta�e fragmenty tworz� cz�� niekoduj�c�.

Przyk�ad 1:
Genotyp AACDBABBBCDAABCBBAAE zawiera geny AACDBABB oraz AABCBB
- ci�g AA wyst�puj�cy za genem AABCBB nie jest pocz�tkiem genu, poniewa� nie wyst�puje
  za nim ci�g BB ko�cz�cy gen;
- cz�� koduj�ca genotypu AACDBABBBCDAABCBBAAE jest r�wna AACDBABBAABCBB. 

Przyk�ad 2:
Genotyp AADBAADDDDEEEBBEE zawiera gen AADBAADDDDEEEBB
- pierwsze pojawienie si� ci�gu AA determinuje pocz�tek genu, dlatego w powy�szym
  genotypie wyst�puje gen AADBAADDDDEEEBB, a nie gen AADDDDEEEBB. 
  
Plik dane_geny.txt zawiera genotypy 1000 osobnik�w z galaktyki Madgen. Ka�dy wiersz
pliku zawiera genotyp jednego osobnika o d�ugo�ci nie wi�kszej ni� 500 znak�w. 
*/

const int SIZE = 1000;
const int MAXLEN = 500;
string tab[SIZE];

/* Wyniki
69.1: 207
69.2: 8;
*/

/* Zadanie 1
Podaj liczb� wszystkich gatunk�w, kt�rych genotypy zapisane s� w pliku dane_gen.txt.
Podaj najwi�ksz� liczb� osobnik�w reprezentuj�cych ten sam gatunek. 
*/

void z1() {
  cout << "Zadanie 1:" << endl;

  int counter[MAXLEN + 1];
  for (int i = 0; i <= MAXLEN; i++) counter[i] = 0;
  for (int i = 0; i < SIZE; i++) counter[tab[i].length()]++;
  
  int maxValue = 0;
  int speciesCounter = 0;
  for (int i = 0; i <= MAXLEN; i++) {
    if (counter[i] > maxValue) maxValue = counter[i];
    if (counter[i] > 0) speciesCounter++;
  }
  
  cout << "Liczba gatunkow: " << speciesCounter << endl;
  cout << "Najwieksza liczba osobnikow: " << maxValue << endl << endl;
}

/*
Wyst�powanie w jakimkolwiek genie ci�gu BCDDC oznacza mutacj� powoduj�c� ma�� odporno��
osobnika na zm�czenie. Podaj, ile osobnik�w spo�r�d tych, kt�rych genotypy zapisane
s� w pliku, ma t� mutacje. 
*/

bool hasBadElement(string s) {
  if (s.length() < 5) return false;
  for (int i = 0; i <= s.length() - 5; i++) {
    if (s[i] == 'B' && s[i + 1] == 'C' && s[i + 2] == 'D' && s[i + 3] == 'D' &&
        s[i + 4] == 'C') {
      return true;    
    }
  }
  return false;
}

bool hasBadGene(string s) {
  string gene = "";
  bool flag = false;
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == 'A' && s[i + 1] == 'A') {
      flag = true;
    }
    if (flag) gene += s[i];
    if (s[i] == 'B' && s[i - 1] == 'B' && flag) {
      flag = false;
      if (hasBadElement(gene)) return true;
      gene = "";
    }
  }
  return false;
}

void z2() {
  cout << "Zadanie 2:" << endl;
  int counter = 0;
  for (int i = 0; i < SIZE; i++) {
    if (hasBadGene(tab[i])) counter++;
  }
  cout << counter << endl << endl;
}

int main() {
  ifstream in("dane_geny.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  
  z1();
  z2();
}
