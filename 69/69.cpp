#include <iostream>
#include <fstream>
using namespace std;

/* Treœæ
Informacjê genetyczn¹ (genotyp) ka¿dego osobnika z galaktyki Madgen opisuje s³owo (napis),
w którym wystêpuj¹ litery ze zbioru {A, B, C, D, E}. Obowi¹zuj¹ przy tym nastêpuj¹ce
zasady:
1. Organizmy ¿yj¹ce na Madgen tworz¹ gatunki g1, g2, g3, …, gdzie gi to zbiór osobników
  o d³ugoœci genotypu równej i.
2. W sk³ad genotypu mog¹ wchodziæ geny. Pierwszy gen rozpoczyna siê pierwsz¹ wystêpuj¹c¹
  w genotypie sekwencj¹ AA, a koñczy siê najbli¿sz¹ napotkan¹ po niej sekwencj¹
  BB. Ka¿dy kolejny gen rozpoczyna siê pierwsz¹ sekwencj¹ AA, wystêpuj¹c¹
  za koñcem poprzedniego genu, i analogicznie koñczy siê najbli¿sz¹ napotkan¹ sekwencj¹ BB.
3. Geny nazywamy czêœci¹ koduj¹c¹ genotypu, pozosta³e fragmenty tworz¹ czêœæ niekoduj¹c¹.

Przyk³ad 1:
Genotyp AACDBABBBCDAABCBBAAE zawiera geny AACDBABB oraz AABCBB
- ci¹g AA wystêpuj¹cy za genem AABCBB nie jest pocz¹tkiem genu, poniewa¿ nie wystêpuje
  za nim ci¹g BB koñcz¹cy gen;
- czêœæ koduj¹ca genotypu AACDBABBBCDAABCBBAAE jest równa AACDBABBAABCBB. 

Przyk³ad 2:
Genotyp AADBAADDDDEEEBBEE zawiera gen AADBAADDDDEEEBB
- pierwsze pojawienie siê ci¹gu AA determinuje pocz¹tek genu, dlatego w powy¿szym
  genotypie wystêpuje gen AADBAADDDDEEEBB, a nie gen AADDDDEEEBB. 
  
Plik dane_geny.txt zawiera genotypy 1000 osobników z galaktyki Madgen. Ka¿dy wiersz
pliku zawiera genotyp jednego osobnika o d³ugoœci nie wiêkszej ni¿ 500 znaków. 
*/

const int SIZE = 1000;
const int MAXLEN = 500;
string tab[SIZE];

/* Wyniki
Zadanie 1:
Liczba gatunkow: 207
Najwieksza liczba osobnikow: 20
Zadanie 2:
8
Zadanie 3:
11 189
Zadanie 4:
249 187
*/

/* Zadanie 1
Podaj liczbê wszystkich gatunków, których genotypy zapisane s¹ w pliku dane_gen.txt.
Podaj najwiêksz¹ liczbê osobników reprezentuj¹cych ten sam gatunek. 
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

/* Zadanie 2
Wystêpowanie w jakimkolwiek genie ci¹gu BCDDC oznacza mutacjê powoduj¹c¹ ma³¹ odpornoœæ
osobnika na zmêczenie. Podaj, ile osobników spoœród tych, których genotypy zapisane
s¹ w pliku, ma tê mutacje. 
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
    if (s[i] == 'B' && s[i + 1] == 'B' && flag) {
      gene += 'B';
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

/* Zadanie 3
Wyznacz i podaj najwiêksz¹ liczbê genów wystêpuj¹cych u jednego osobnika. Podaj te¿ najwiêksz¹
d³ugoœæ genu zapisanego w ca³ym pliku. 
*/

void z3() {
  cout << "Zadanie 3:" << endl;
  string s, gene;
  bool flag;
  int geneCounter, maxGeneCounter = 0;
  int maxGeneLength = 0;
  for (int i = 0; i < SIZE; i++) {
    s = tab[i];
    gene = "";
    geneCounter = 0;
    flag = false;
    for (int j = 0; j < s.length() - 1; j++) {
      if (s[j] == 'A' && s[j + 1] == 'A') {
        flag = true;
      }
      if (flag) gene += s[j];
      if (s[j] == 'B' && s[j + 1] == 'B' && flag) {
        gene += 'B';
        flag = false;
        geneCounter++;
        if (gene.length() > maxGeneLength) maxGeneLength = gene.length();
        gene = "";
      }
    }
    if (geneCounter > maxGeneCounter) maxGeneCounter = geneCounter;
  }
  cout << maxGeneCounter << " " << maxGeneLength << endl << endl;
}

/* Zadanie 4
Genotyp odczytywany z materia³u biologicznego mo¿e byæ odkodowany w kierunku od strony
lewej do prawej lub odwrotnie: od strony prawej do lewej. Genotyp nazywaæ bêdziemy
odpornym, jeœli czytany od strony lewej do prawej oraz od strony prawej do lewej ma dok³adnie
tak¹ sam¹ czêœæ koduj¹c¹. Natomiast genotyp silnie odporny to taki, który czytany od
strony lewej do prawej oraz od strony prawej do lewej daje dok³adnie ten sam napis. (Inaczej
mówi¹c, genotyp jest silnie odporny, gdy jest palindromem). 
Wyznacz liczbê genotypów odpornych oraz liczbê genotypów silnie odpornych. 
*/

bool isPalindrome(string s) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != s[s.length() - i - 1]) return false;
  }
  return true;
}

string allGenes(string s) {
  string genes = "";
  bool flag = false;
  string gene = "";
  for (int i = 0; i < s.length() - 1; i++) {
    if (s[i] == 'A' && s[i + 1] == 'A') {
      flag = true;
    }
    if (flag) gene += s[i];
    if (s[i] == 'B' && s[i + 1] == 'B' && flag) {
      gene += 'B';
      flag = false;
      genes += gene;
      gene = "";
    }
  }
  return genes;
}

string reverse(string s) {
  string result = "";
  for (int i = 0; i < s.length(); i++) {
    result = s[i] + result;
  }
  return result;
}

void z4() {
  cout << "Zadanie 4:" << endl;
  int resistantCounter = 0, strongResistantCounter = 0;
  string s;
  for (int i = 0; i < SIZE; i++) {
    s = tab[i];
    if (isPalindrome(s)) strongResistantCounter++;
    if (allGenes(s) == allGenes(reverse(s))) resistantCounter++;
  }
  cout << resistantCounter << " " << strongResistantCounter << endl << endl;
}

int main() {
  ifstream in("dane_geny.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  
  z1();
  z2();
  z3();
  z4();
}
