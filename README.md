<a name="start"></a>
# matura2018
*Practice for the 2018 Matura exam*

Rozwiązania do zadań w przygotowaniu do matury z informatyki 2018

## Spis treści
* [Linki do zadań](#linki)
* [O zadaniach](#zadania)
* [Ściągawka](#sciagawka)
* [Podstawy](#podstawy)

<a name="linki"></a>
## Linki do zadań

* [Arkusze CKE](https://cke.gov.pl/egzamin-maturalny/egzamin-w-nowej-formule/arkusze/)
* [Zbiór zadań CKE](https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Materialy/Zbiory_zadan/Matura_Zbi%C3%B3r_zada%C5%84_Informatyka.pdf)
* [Pobierz pliki do zbioru zadań](https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Materialy/Zbiory_zadan/inf-pr-dane.zip)
* [Informator CKE](https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Informatory/2015/Informatyka.pdf)

<a name="zadania"></a>
## O zadaniach

Zadanie | Trudność | Komentarz
------- | -------- | ---------
58 | ★★★☆☆ | Zamiana między dwójkowym, czwórkowym i ósemkowym
59 | ★★★☆☆ | Liczby pierwsze, rozkład na czynniki, palindromy
60 | ★★☆☆☆ | Dzielniki, liczby względnie pierwsze
61 | ★★☆☆☆ | Ciągi arytmetyczne, sprawdzanie poprawności
62 | ★★★★☆ | Zamiana między ósemkowym i dziesiętnym
63 | ★★★☆☆ | Zamiana między dwójkowym i dziesiętnym, liczby półpierwsze
64 | ★★★★★ | Bity parzystości, tablice dwuwymiarowe, sprawdzanie poprawności
65 | ★★★★☆ | Ułamki
66 | ★☆☆☆☆ | Działania na liczbach
67 | ★★★★★ | Ciąg Fibonacciego, rysunek fraktala
68 | ★★★☆☆ | Anagramy, działania na stringach
69 | ★★★★★ | Działania na stringach (genomy)
72 | ★☆☆☆☆ | Podstawowe działania na stringach
73 | ★★★★☆ | Porównywanie słów, liczenie częstotliwości
74 | ★★☆☆☆ | Działania na stringach (hasła)
75 | ★★★★☆ | Szyfrowanie afiniczne
76 | ★★★☆☆ | Szyfrowanie przestawieniowe
77 | ★★★★★ | Szyfr Vingerere'a
78 | ★★★★★ | Dość.

70 i 71 to zadania z matematyki.

<a name="sciagawka"></a>
## Ściągawka:

- Przydatne biblioteki
```c++
#include <cmath>
pow(base, exponent); // pow(2, 3) == 8
sqrt(x); // sqrt(25) == 5
ceil(x); // ceil(3.5) == 4
floor(x); // floor(3.5) == 3
abs(x); // abs(-5) == 5

#include <algorithm>
sort(first, last); // Przykład w Sortowanie

#include <iomanip>
setprecision(n); // Przykład w Ustawienie dokładności wyświetlania
```

- Sortowanie
```c++
#include <algorithm>
sort(tab, tab + SIZE);
sort(string.begin(), string.end());

// Bubble sort
for (int i = 0; i < SIZE; i++) {
  for (int j = 0; j < SIZE - i; j++) {
    if (tab[j] > tab[j + 1]) {
      temp = tab[j];
      tab[j] = tab[j + 1];
      tab[j + 1] = temp;
    }
  }
}
```

- Zapisanie na koniec pliku
```c++
ofstream out("wynik.txt", ios::app);
```

- Ustawienie dokładności wyświetlania
```c++
#include <iomanip>
cout << setprecision(3) << 0.01234;
// Wynik: 0.0123
cout << fixed << setprecision(3) << 0.01234;
// Wynik: 0.012
```

- Algorytm Euklidesa (nwd)
```c++
int nwd(int x, int y) {
  if (x < y) return nwd(y, x);
  if (y == 0) return x;
  return nwd(y, x % y);
}
```

- Czy liczba jest pierwsza
```c++
bool isPrime(int n) {
  if (n <= 1) return false;
  if (n % 2 == 0 && n != 2) return false;
  for (int i = 3; i * i <= n; i += 2)
    if (n % i == 0) return false;
  return true;
}
```

- string base2 -> int base10
```c++
int binToDec(string bin) {
  int n = 0;
  for (int i = 0; i < bin.length(); i++)
    n = n * 2 + (bin[i] - '0');
  return n;
}
```

<a name="podstawy"></a>
## Podstawy

- Przykładowy program wczytujący i wypisujący dane z pliku
```c++
#include <iostream> // cout
#include <fstream> // file stream
using namespace std;

int main() {
  const int ROZMIAR = 1000;
  int tabela[ROZMIAR];
  ifstream input("plik.txt"); // ifstream = input file stream

  for (int i = 0; i < ROZMIAR; i++) {
    input >> tabela[i];
    cout << tabela[i];
  }

  input.close();
}
```

- Wczytanie z pliku do pojedynczej zmiennej
```c++
ifstream input("plik.txt");
int n;
while (input >> n) cout << n;
input.close();
```

- Zapisanie zmiennej do pliku
```c++
/* Jeżeli plik nie istnieje to zostanie utworzony. Przed zapisem cała zawartość 
 * pliku będzie usunięta. O zapisaniu na koniec pliku jest w Ściągawce. 
 */
ofstream output("plik.txt"); // ofstream = output file stream
string wiadomosc = "Michał Tarnecki to super kolega";
output << wiadomosc;
output.close();
```

[Wróć do góry](#start)