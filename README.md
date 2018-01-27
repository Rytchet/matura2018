# matura2018
*Practice for the 2018 Matura exam*

Rozwiązania do zadań w przygotowaniu do matury z informatyki 2018


### Linki do zadań:

* [Arkusze CKE](https://cke.gov.pl/egzamin-maturalny/egzamin-w-nowej-formule/arkusze/)
* [Zbiór zadań CKE](https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Materialy/Zbiory_zadan/Matura_Zbi%C3%B3r_zada%C5%84_Informatyka.pdf)
* [Informator CKE](https://cke.gov.pl/images/_EGZAMIN_MATURALNY_OD_2015/Informatory/2015/Informatyka.pdf)

### Ściągawka:

- Zapisanie na koniec pliku
```c++
ofstream out("wynik.txt", ios::app);
```

- Ustawienie dokładności wyświetlania
```c++
#include <iomanip> // setprecision()
cout << setprecision(3) << 0.01234;
// Wynik: 0.0213
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
  for (int i = 0; i < bin.length(); i++) {
    n = n * 2 + (bin[i] - '0');
  return n;
}
```
