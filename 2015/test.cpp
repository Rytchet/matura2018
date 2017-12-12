#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
  ifstream in("liczby.txt");
 
  if(in.is_open())
  {
    //liczba - wczytana liczba z pliku
    //pomMin - przechowuje najmniejsza liczbe
    //pomMax - przechowuje najwieksza liczbe
    string liczba, pomMin, pomMax;
 
    //i - zlicza wiersze, nrMin - wiersz z najmniejsza liczba
    //nrMax - wiersz z najwieksza liczba
    int nrMin = 1, nrMax = 1;
 
    in>>liczba; //wczytanie pierwszej liczby
 
    pomMin = pomMax = liczba;
 
    for(int i=2; i<1001; i++)
    {
      in>>liczba;
      //szukanie maksymalnej --------------------------------------
      //jesli wczytana liczba ma wiecej znaków
      //oznacza to, ze jest wieksza
      if(liczba.size() > pomMax.size())
      {
        pomMax = liczba; //zapamietaj ja
        nrMax = i; //zapamietaj wiersz
      } 
      else
        //jesli maja po tyle samo znaków
        //to trzeba sprawdzic, która jest wieksza
        //operator > porównuje leksykograficznie
        if(liczba.size()==pomMax.size())
          if(liczba > pomMax)
          {
            //zapamietujemy ja
            pomMax = liczba;
            //oraz jej pozycje
            nrMax = i;
          }
      //szukanie minimalnej --------------------------------------
      //jesli wczytana liczba ma mniej znaków
      //oznacza to, ze jest mniejsza
      //operator < porównuje leksykograficznie
      if(liczba.size() < pomMin.size())
      {
        pomMin = liczba; //zapamietaj ja
        nrMin = i; //zapamietaj wiersz
      } 
      else
        //jesli maja po tyle samo znaków
        //to trzeba sprawdzic, która jest mniejsza
        if(liczba.size()==pomMin.size())
          if(liczba < pomMin)
          {
            //zapamietujemy ja
            pomMin = liczba;
            //oraz jej pozycje
            nrMin = i; 
          }  
    }
 
    cout<<"Najmniejsza znajduje sie we wierszu: "<<nrMin<<endl;
    cout<<"Najwieksza znajduje sie we wierszu: "<<nrMax<<endl;
    cin.get();
    in.close();
  }
  else
    cout<<"Problem z otwarciem pliku \"liczby.txt\"";
 
 
  return 0;
}
