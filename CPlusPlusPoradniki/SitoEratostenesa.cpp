#include <bits/stdc++.h>

using namespace std;

//Tablica w ktorej bedziemy oznaczac liczby pierwsze i zlozone
int pierwsze[1000009];

void sito(int n){
    //Ustawiamy 0 i 1 jako liczby zlozone
    pierwsze[0]=1;
    pierwsze[1]=1;

    //Przechodzimy po wszystkich liczbach od 2 do pierwiastek(koniec)
    for(int i=2;i*i<=n;i++){
        //Jezeli napotkamy liczbe dla ktorej pierwsze[i]=0 to oznacza ze jest to liczba pierwsza, usuwamy wiec jej wielokrotnosci
        if(pierwsze[i]==0){
            //Zaczynamy od kwadratu pierwszej poniewaz wczesniejsze wielokrotnosci zostaly usuniete.
            //Np. dla liczby pierwszej 3 liczba 6 zostala usunieta przez liczbe pierwsza 2.
            //Np. przy liczbie pierwszej 7, liczby 14,21,28,35,42 zostaly usuniete przez wczesniejsze liczby pierwsze itd.
            for(int j=i*i;j<=n;j=j+i){
                pierwsze[j]=1;
            }
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    sito(n);

    //Wypisujemy liczby pierwsze
    for(int i=0;i<=n;i++){
        if(pierwsze[i]==0){
            cout<<i<<" ";
        }
    }
    return 0;
}
