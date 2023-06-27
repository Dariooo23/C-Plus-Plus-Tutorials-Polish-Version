#include <bits/stdc++.h>

using namespace std;

int main()
{
    int tab[100000];
    int pref[100000];
    int n;

    //Wczytujemy rozmiar tablicy z liczbami
    cin>>n;
    //Wczytujemy wszystkie liczby do tablicy
    for(int i=1;i<=n;i++){
        cin>>tab[i];
    }

    //Ustawiamy zerowy indeks tablicy prefiksowej na zero dla latwiejszej obslugi zapytan typu {0,i}
    pref[0]=0;
    //Obliczamy kolejne sumy dla przedzialow {0,i}
    for(int i=1;i<=n;i++){
        pref[i]=pref[i-1]+tab[i];
    }

    int q;
    //Wczytujemy ilosc zapytan
    cin>>q;
    for(int i=0;i<q;i++){
        int poczatek,koniec;
        //Wczytujemy poczatek i koniec przedzialu o ktory sie pytamy
        cin>>poczatek>>koniec;
        //Odpowiadamy korzystajac z tablicy prefiksowej
        cout<<pref[koniec]-pref[poczatek-1]<<endl;
    }


    return 0;
}