//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int rozmiar_poddrzewa;

vector<int> zbior_a;
vector<int> zbior_b;
vector<int> poddrzewa;
vector<int> odleglosci1;
vector<int> odleglosci2;
vector<vector<int>> graf;


int oblicz_poddrzewa(int s, int p){
    poddrzewa[s]=1;

    for(const int &v:graf[s]){
        if(v==p)continue;
        poddrzewa[s]=poddrzewa[s]+oblicz_poddrzewa(v,s);
    }
    
    return poddrzewa[s];
}
pair<int,int> znajdz_centroidy(int s, int p, int liczba_pol){
    for(const int &v:graf[s]){
        if(v==p)continue;
        if(2*poddrzewa[v]>liczba_pol)return znajdz_centroidy(v,s,liczba_pol);
    }

    if(2*poddrzewa[p]==liczba_pol){
        return {s,p};
    }else{
        return {s,-1};
    }
}
void oblicz_odleglosci(int nr_centroidu,int s,int p){
    if(nr_centroidu==1){
        odleglosci1[s]=odleglosci1[p]+1;
    }else{
        odleglosci2[s]=odleglosci2[p]+1;
    }

    for(const int &v:graf[s]){
        if(v==p)continue;
        oblicz_odleglosci(nr_centroidu,v,s);
    }return;
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

    pair<int,int> centroidy;
    poddrzewa.resize(liczba_pol+1);                                                                                             //Aby przyśpieszyć program z O(n^3) do O(n^2) należy zauważyć że wygrywa ta osoba, która jest bliżej centroidu, czyli pola dzielącego cały graf
    odleglosci1.resize(liczba_pol+1);                                                                                           //na mniejsze o wielkości maksymalnie n/2.
    odleglosci2.resize(liczba_pol+1);           

    oblicz_poddrzewa(1,-1);                                                                                                     //Obliczamy rozmiary poddrzew dla każdego punktu, ponieważ będą potrzebne do znalezienia centroidów.
    centroidy=znajdz_centroidy(1,-1,liczba_pol);                                                                                //Znajdujemy centroidy (W większości przypadków będzie to jeden centroid jednak czasami mogą wystąpić 2 dzielące cały graf na 2 równe części).

    odleglosci1[centroidy.first]=0;         
    oblicz_odleglosci(1,centroidy.first,-1);                                                                                    //Aby sprawdzić kto jest bliżej centroidu należy obliczyć odległości od nich do każdego punktu.
    if(centroidy.second!=-1){           
        odleglosci2[centroidy.second]=0;                                                                                                   
        oblicz_odleglosci(2,centroidy.second,-1);           
    }                               

    for(int i=0;i<rozmiar_zbioru_a;i++){                                                                                        
        for(int j=0;j<rozmiar_zbioru_b;j++){                                                                                    
            if(zbior_a[i]==zbior_b[j])continue;                                                                                 //W przypadku gdy istnieje 1 centroid to gracz A wygrywa kiedy jest w stanie do niego dojść szybciej niż gracz B.
            if(centroidy.second==-1){                                                                                           //W przypadku gdy istnieją 2 centroidy to gracz A wygrywa kiedy jest w stanie dojśc do obu centroidów szybciej niż gracz B.
                if(odleglosci1[zbior_a[i]]<=odleglosci1[zbior_b[j]])wynik++;            
            }else{          
                if(max(odleglosci1[zbior_a[i]],odleglosci2[zbior_a[i]])<=min(odleglosci1[zbior_b[j]],odleglosci2[zbior_b[j]]))wynik++;
            }           
        }                                                                                                                       //Złożoność całego algorytmu będzię więc wynosić O(n+n^2),
    }                                                                                                                           //ponieważ wykonujemy w czasie liniowym O(n) obliczenia pozwalające wyznaczyć centroidy,
                                                                                                                                //oraz ich odległości od pozostałych punktów też w czasie O(n),
                                                                                                                                //oraz dla każdego pola ze zbioru A i dla każdego pola ze zbioru B (Których jest łącznie n^2)
                                                                                                                                //sprawdzamy w czasie stałym O(1) który punkt jest bliżej centroidu.
    cout<<wynik;
    return 0;
}
 