#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;

    int tab[100000];

    //Wczytujemy nasz ciag liczb
    for(int i=0;i<n;i++){
        cin>>tab[i];
    }

    //Sortujemy go podajac tablice do posortowania oraz jej koniec
    sort(tab,tab+n);

    int szukana;
    cin>>szukana;
    //Ustawiamy poczatkowe wartosci w zmiennych do wyszukiwania binarnego
    int poczatek=0,koniec=n,srodek;

    //Dopoki poczatek jest mniejszy niz koniec kontynuujemy dzialanie programu
    while(poczatek<koniec){
        //Obliczamy srodek sprawdzanego przedzialu
        srodek=(poczatek+koniec)/2;

        //Jezeli aktualna wartosc jest mniejsza lub rowna szukanej to przechodzimy na prawo w przeciwnym razie na lewo
        if(tab[srodek]<=szukana){
            poczatek=srodek+1;
        }else{
            koniec=srodek;
        }
    }

    //Wypisujemy szukany przez nas indeks znajdujacy sie w zmiennej poczatek
    cout<<poczatek;

    //Jezeli chcielibysmy znalezc pierwszy element ktory jest rowny lub wiekszy niz szukany to wystarczyloby usunac znac rownosci z if
    return 0;
}