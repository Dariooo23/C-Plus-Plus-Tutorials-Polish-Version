#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int a=7,b=-10,c=125,d=60;

    cout<<min(d,c)<<endl; //Funkcja zwroci 60
    cout<<max(b,a)<<endl; //Funkcja zwroci 7

    cout<<min({a,b,c,d})<<endl; //Funkcja zwroci -10
    cout<<max({a,b,c,d})<<endl; //Funkcja zwroci 125

    int minimum=1e9,maksimum=-1e9;  //Poczatkowo wartosc "minimum" ustawiamy na bardzo duza liczbe, a "maksimum" na bardzo mala,
                                    //Poniewaz gdyby mialy poczatkowo wartosc 0 to, np. podczas sprawdzania liczb {10,15,20,5} dla funkcji minimum otrzymalibysmy wartosc 0 ktorej nie ma posrod tych liczb

    int tab[5]={1,50,-10,23,10};    //Tablica z przykladowymi wartosciami

    for(int i=0;i<5;i++){           //Sprawdzamy kazdy indeks w tablicy w poszukiwaniu najmniejszej wartosci
        if(minimum>tab[i]){
            minimum=tab[i];
        }
    }
    cout<<minimum<<endl;


    for(int i=0;i<5;i++){           //Sprawdzamy kazdy indeks w tablicy w poszukiwaniu najwiekszej wartosci
        if(maksimum<tab[i]){
            maksimum=tab[i];
        }
    }
    cout<<maksimum<<endl;

    return 0;
}
 
