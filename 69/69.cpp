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
69.1: 207
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



int main() {
  ifstream in("dane_geny.txt");
  for (int i = 0; i < SIZE; i++) in >> tab[i];
  in.close();
  
  z1();
}
