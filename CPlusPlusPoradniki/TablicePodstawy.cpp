#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int tab[20]; //Tworzymy tablice przechowujaca zmienne typu "int" o nazwie "tab" i rozmiarze 20.
    int a=10,b=17,c=23;


    tab[a]=b;   //Przypisujemy wartosc tablicy na indeksie "a" (czyli 10), wartosc 17.
    tab[b]=c-a; //Przypisujemy wartosc tablicy na indeksie "b" (czyli 17), wartosc "c"-"a" (13).
    //tab[c]    //Nie mozemy przypisac wartosci tab[c] poniewaz indeks "c" jest wiekszy niz rozmiar tablicy.


    int tab2[20][20]; //Tworzymy tablice dwuwymiarowa przechowujaca zmienne typu "int" o nazwie "tab2" i rozmiarze 20 x 20.
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            tab2[i][j]=i+j;      //Przypisujemy kazdej parze indeksow {i,j} ich sume
        }
    }

    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            cout<<tab2[i][j]<<" ";     //Wypisujemy te wartosci
        }
        cout<<endl;                    //Po wypisaniu kazdego wiersza tablicy dajemy nowy znak lini dla przejrzystosci wypisywanych rzeczy
    }

    return 0;
}