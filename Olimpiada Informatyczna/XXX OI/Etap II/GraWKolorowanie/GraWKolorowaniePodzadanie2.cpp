#include <bits/stdc++.h>

using namespace std;

int rozmiar_poddrzewa;

vector<int> zbior_a;
vector<int> zbior_b;
vector<int> sciezka;
vector<int> rodzice;
vector<vector<int>> graf;

void oblicz_rodzicow(int s, int p){
    rodzice[s]=p;

    for(const int &v:graf[s]){
        if(v==p)continue;
        oblicz_rodzicow(v,s);
    }return;
}
void oblicz_rozmiar_poddrzewa(int s,int p,int blokada){
    rozmiar_poddrzewa++;
    for(const int &v:graf[s]){
        if(v==p || v==blokada)continue;
        oblicz_rozmiar_poddrzewa(v,s,blokada);
    }return;
}
int znajdz_blokade(int pole1,int pole2,int liczba_pol){
    rodzice.resize(liczba_pol+1);                                           //Tablica ta przetrzymuję dla każdego punktu jego poprzednika.
        
    oblicz_rodzicow(pole1,-1);                                              //Uzupełniamy tablice "rodzice" rozchodząc się po grafie, złożoność funkcji oblicz_rodzicow() to O(n), ponieważ odwiedzamy każde pole w grafie jeden raz.
        
    int pole=pole2;     
    while(pole!=pole1){                                                     //Odtwarzamy teraz ścieżkę za pomocą talbicy "rodzice" cofając się przodkami z pole2 aż natrafimy na pole1
        sciezka.push_back(pole);                                            //w najgorszym przypadku odwiedzimy wszystkie pola w grafie więc złożoność tego algorytmu wynosi O(n).
        pole=rodzice[pole];     
    }sciezka.push_back(pole);       
        
    int blokada=sciezka[sciezka.size()/2];                                  //Optymalną strategią jest jak najszybsze dojścię do przeciwnika, aby zablokować mu jak największą część grafu.
                                                                            //Każdy zawodnik będzię więc chciał jak najbszyciej dotrzeć do przeciwnika, przez co spotkają się w połowie ścieżki.
                                                                            //Obliczamy blokade dla gracza ze zbiorem A (Miejsce które zostanie już zajętę przez gracza B, a nie przez niego).
    return blokada;                                                         //Cały algorytm znajdz_blokade działa w złożoności O(n), ponieważ wykonujemy tutaj przejścię po całym grafie 2 razy (W funkcji oblicz_rodziców oraz podczas odtwarzania ścieżki),
                                                                            //wychodzi więc 2n, jednak stała 2 jest pomijalnie mała.
}                        

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int liczba_pol,wynik=0;
    cin>>liczba_pol;

    graf.resize(liczba_pol+1);

    for(int i=1;i<liczba_pol;i++){
        int pole1,pole2;
        cin>>pole1>>pole2;

        graf[pole1].push_back(pole2);
        graf[pole2].push_back(pole1);
    }

    int rozmiar_zbioru_a,rozmiar_zbioru_b,liczba_aktualizacji;
    cin>>rozmiar_zbioru_a>>rozmiar_zbioru_b>>liczba_aktualizacji;

    for(int i=0;i<rozmiar_zbioru_a;i++){
        int pole1;
        cin>>pole1;
        zbior_a.push_back(pole1);
    }
    for(int i=0;i<rozmiar_zbioru_b;i++){
        int pole1;
        cin>>pole1;
        zbior_b.push_back(pole1);
    }

    for(int i=0;i<rozmiar_zbioru_a;i++){                                           
        for(int j=0;j<rozmiar_zbioru_b;j++){                                      
            if(zbior_a[i]==zbior_b[j])continue;
            int blokada=znajdz_blokade(zbior_a[i],zbior_b[j],liczba_pol);          //Funkcja znajdz_blokade(zbior_a[i],zbior_b[j],liczba_pol) w najgorszym wypadku musi przejść przez wszystkie pola aby znaleźć ścieżkę.

            rozmiar_poddrzewa=0;
            oblicz_rozmiar_poddrzewa(zbior_a[i],-1,blokada);

            if(2*rozmiar_poddrzewa>liczba_pol){                                    //Jeżeli rozmiar_poddrzewa gracza A jest większy niż połowa grafu to wygrywa.
                wynik++;               
            }              
        }                                                                          //Złożoność całego algorytmu będzię więc wynosić O(n^3),ponieważ dla każdego pola ze zbioru A i dla każdego pola ze zbioru B (Których jest łącznie n^2) 
    }                                                                              //odpalamy algorytm znajdz_blokade(zbior_a[i],zbior_b[j],liczba_pol) i algorytm oblicz_rozmiar_poddrzewa(zbior_a[i],-1,blokada) działające łącznie w czasie O(2n),
                                                                                   //gdzie stałą 2 pomijamy ze względu na jej mały wpływ na złożoność czasową programu.

    cout<<wynik;
    return 0;
}
 
