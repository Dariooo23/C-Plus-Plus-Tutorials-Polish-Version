#include <bits/stdc++.h>

using namespace std;

int rozmiar_poddrzewa;
long long int podstawa=(1<<20);

vector<int> zbior_a;
vector<int> zbior_b;
vector<int> poddrzewa;
vector<int> powtorzenia;
vector<int> odleglosci1;
vector<int> odleglosci2;
vector<vector<int>> graf;
vector<int> ile_odleglosci1_b;
vector<int> ile_odleglosci2_b;
vector<int> ile_odleglosci1_a;
vector<int> ile_odleglosci2_a;
vector<long long int> drzewo_b(podstawa*2);
vector<long long int> drzewo_a(podstawa*2);

long long int query_b(int poczatek,int koniec){
    poczatek=poczatek+podstawa;
    koniec=koniec+podstawa;
    long long int wynik=0;

    wynik=wynik+drzewo_b[poczatek];
    if(poczatek!=koniec)wynik=wynik+drzewo_b[koniec];

    while(poczatek/2!=koniec/2){
        if(poczatek%2==0){
            wynik=wynik+drzewo_b[poczatek+1];
        }
        if(koniec%2==1){
            wynik=wynik+drzewo_b[koniec-1];
        }
        poczatek=poczatek/2;
        koniec=koniec/2;
    }
    return wynik;
}
void update_b(int indeks,int wartosc){
    indeks=indeks+podstawa;
    drzewo_b[indeks]=drzewo_b[indeks]+wartosc;

    while(indeks!=1){
        indeks=indeks/2;
        drzewo_b[indeks]=drzewo_b[indeks]+wartosc;
    }return;
}
long long int query_a(int poczatek,int koniec){
    poczatek=poczatek+podstawa;
    koniec=koniec+podstawa;
    long long int wynik=0;

    wynik=wynik+drzewo_a[poczatek];
    if(poczatek!=koniec)wynik=wynik+drzewo_a[koniec];

    while(poczatek/2!=koniec/2){
        if(poczatek%2==0){
            wynik=wynik+drzewo_a[poczatek+1];
        }
        if(koniec%2==1){
            wynik=wynik+drzewo_a[koniec-1];
        }
        poczatek=poczatek/2;
        koniec=koniec/2;
    }
    return wynik;
}
void update_a(int indeks,int wartosc){
    indeks=indeks+podstawa;
    drzewo_a[indeks]=drzewo_a[indeks]+wartosc;

    while(indeks!=1){
        indeks=indeks/2;
        drzewo_a[indeks]=drzewo_a[indeks]+wartosc;
    }return;
}



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

    long long int liczba_pol,wynik=0;
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

    pair<int,int> centroidy;       //Aby przyśpieszyć program z O(n^3) do O(n^2) należy zauważyć że wygrywa ta osoba, która jest bliżej centroidu, czyli pola dzielącego cały graf
    poddrzewa.resize(liczba_pol+1);//na mniejsze o wielkości maksymalnie n/2. 
    powtorzenia.resize(liczba_pol+1);    
    odleglosci1.resize(liczba_pol+1,1e9);
    odleglosci2.resize(liczba_pol+1,1e9);   
    ile_odleglosci1_b.resize(liczba_pol+1,0);
    ile_odleglosci2_b.resize(liczba_pol+1,0);
    ile_odleglosci1_a.resize(liczba_pol+1,0);
    ile_odleglosci2_a.resize(liczba_pol+1,0);         

    oblicz_poddrzewa(1,-1);//Obliczamy rozmiary poddrzew dla każdego punktu, ponieważ będą potrzebne do znalezienia centroidów.
    centroidy=znajdz_centroidy(1,-1,liczba_pol);//Znajdujemy centroidy (W większości przypadków będzie to jeden centroid jednak czasami mogą wystąpić 2 dzielące cały graf na 2 równe części).

    odleglosci1[0]=-1;         
    oblicz_odleglosci(1,centroidy.first,0);//Aby sprawdzić kto jest bliżej centroidu należy obliczyć odległości od nich do każdego punktu.
    for(int i=0;i<rozmiar_zbioru_b;i++){
        ile_odleglosci1_b[odleglosci1[zbior_b[i]]]++;
    }
    for(int i=0;i<rozmiar_zbioru_a;i++){
        ile_odleglosci1_a[odleglosci1[zbior_a[i]]]++;
    }
    if(centroidy.second!=-1){           
        odleglosci2[0]=-1;                                                                                                   
        oblicz_odleglosci(2,centroidy.second,0);       
        for(int i=0;i<rozmiar_zbioru_b;i++){
            ile_odleglosci2_b[odleglosci2[zbior_b[i]]]++;
        }    
        for(int i=0;i<rozmiar_zbioru_a;i++){
            ile_odleglosci2_a[odleglosci2[zbior_a[i]]]++;
        }    
    }                           

    //W podzadaniu 3 udało się usprawnić odnajdywanie punktu podziału grafu między dwóch graczy, jednak dalej pozostaję nam do sprawdzenia n^2 punktów.
    //Musimy więc w jakiś sposób teraz dla każdego punktu ze zbioru A sprawdzić w czasie krótszym niż liniowym wszystkie punkty ze zbioru B z którymi wygrywa.
    //Aby to zrobić możemy stworzyć drzewo przedziałowe na które dodamy wszystkie punkty ze zbioru B, czyli jak minimalna odległość od centroidu punktu wynosi 
    //np. 4 to zwiększamy wartość na indeksie 4 dodając tam 1. Punktów tych jest n, a każda aktualizacja drzewa zajmie log(n) więc te operacje zajmą nam
    //łącznie O(n log(n)) czasu.
    //Następnie dla każdego punktu w zbiorze A możemy w czasie O(log(n)) zapytać się ile jest punktów, które są dalej niż on od Centroidów, pytając się
    //na przedziale (min(odleglosci1[i],odleglosci2[i])+1,n) gdzie "i" to punkt te zbioru A. Czyli dla wszystkich punktów w czasie O(n log(n)).

    for(int i=0;i<rozmiar_zbioru_b;i++){//Dodajemy na drzewo odleglosci punktów ze zbioru B biorąc minimum z odleglości pierwszego i drugiego centroidu
        update_b(min(odleglosci1[zbior_b[i]],odleglosci2[zbior_b[i]]),1);
    }
    for(int i=0;i<rozmiar_zbioru_a;i++){//Dodajemy na drzewo odleglosci punktów ze zbioru A biorąc minimum z odleglości pierwszego i drugiego centroidu
        update_a(min(odleglosci1[zbior_a[i]],odleglosci2[zbior_a[i]]),1);
    }
    for(int i=0;i<rozmiar_zbioru_a;i++){//Dla punktów ze zbioru A musimy rozpatrzyć dwa przypadki. Pierwszy, zliczamy wszystkie punkty ze zbioru B, które są dalej od centroidu, który jest bliżej
        wynik=wynik+query_b(min(odleglosci1[zbior_a[i]],odleglosci2[zbior_a[i]])+1,liczba_pol);                                                                                                                
        if(odleglosci1[zbior_a[i]]<odleglosci2[zbior_a[i]]){//Tablice ile_odleglosci możemy obliczyć sprawdzając dla każdego punktu ze zbioru B jego odległość;
            wynik=wynik+ile_odleglosci1_b[odleglosci1[zbior_a[i]]];
        }else{
            wynik=wynik+ile_odleglosci2_b[odleglosci2[zbior_a[i]]];
        }

    }
    for(int i=0;i<rozmiar_zbioru_b;i++){//Od wyniku należy jeszcze odjąć punkty, które nie spełniają założeń zadania czyli że wybrane punky ze zbioru A i B są identyczne.
        powtorzenia[zbior_b[i]]=1;      //Robimy to w czasie O(n) zapisując sobie do tablicy punkty z jednego zbioru i potem dla drugiego patrzymy które się powtarzają.
    }
    for(int i=0;i<rozmiar_zbioru_a;i++){
        if(powtorzenia[zbior_a[i]]==1){
            wynik--;
        }
        powtorzenia[zbior_a[i]]++;
    }
    
    cout<<wynik<<endl;//Mamy już prawie rozwiązanie wzorcowe, teraz należy tylko obsłużyć operację dodawania i usuwania ze zbiorów,
                      //jednak mając strukture drzew przedziałowych nie będzie to trudne i każdą zmianę będziemy mogli obsłużyć w O(log(n)).

    for(int i=1;i<=liczba_aktualizacji;i++){
        char zbior,operacja;
        int pole;

        cin>>zbior>>operacja>>pole;

        if(zbior=='A'){                                                                      //Przy aktualizacji zbioru A wykonujemy te same operacje co wczesniej czyli pytamy się na przedziale o punkty B stricte znajdujące
            if(operacja=='+'){                                                               //się dalej od centroidu niż punkt A, oraz dodajemy te które znajdują się w takiej samej odległości od centroidu,
                wynik=wynik+query_b(min(odleglosci1[pole],odleglosci2[pole])+1,liczba_pol);  //który jest bliższy punktu A.  
                update_a(min(odleglosci1[pole],odleglosci2[pole]),1);                                      
                if(odleglosci1[pole]<odleglosci2[pole]){
                    wynik=wynik+ile_odleglosci1_b[odleglosci1[pole]];
                }else{
                    wynik=wynik+ile_odleglosci2_b[odleglosci2[pole]];
                }

                ile_odleglosci1_a[odleglosci1[pole]]++;//Należy też dodać ten punkt w tablicy ile_odleglosci dla przyszłych zapytań
                if(centroidy.second!=-1){
                    ile_odleglosci2_a[odleglosci2[pole]]++;
                }
                if(powtorzenia[pole]==1){//Musimy jeszcze pamiętać o zmniejszeniu wyniku jeżeli nowo dodany punkt do zbioru A znajduję się również w zbiorze B.
                    wynik--;
                }
                
                powtorzenia[pole]++;
            }else{
                wynik=wynik-query_b(min(odleglosci1[pole],odleglosci2[pole])+1,liczba_pol);//Operacja usunięcia wygląda prawie identycznie, w tym przypadku zmniejszamy wynik   
                update_a(min(odleglosci1[pole],odleglosci2[pole]),-1);                     //Musimy też pamiętać o usunięciu tego punktu z drzewa przedziałowego oraz tablic ile_odleglosci.
                if(odleglosci1[pole]<odleglosci2[pole]){
                    wynik=wynik-ile_odleglosci1_b[odleglosci1[pole]];
                }else{
                    wynik=wynik-ile_odleglosci2_b[odleglosci2[pole]];
                }

                ile_odleglosci1_a[odleglosci1[pole]]--;
                if(centroidy.second!=-1){
                    ile_odleglosci2_a[odleglosci2[pole]]--;
                }
                if(powtorzenia[pole]==2){//Musimy również pamiętać o sprawdzeniu powtórzeń.                                         
                    wynik++;
                }  
                powtorzenia[pole]--;
            }
        }else{                //W przypadku zmiany zbioru B będziemy potrzebować drugiego drzewa przedziałowego w którym będziemy przetrzymywać
            if(operacja=='+'){//odległości punktów ze zbioru A.
                wynik=wynik+query_a(0,min(odleglosci1[pole],odleglosci2[pole])-1);//Przy aktualizacji zbioru B wykonujemy podobne operacje do tych podczas aktualizacji zbioru A, czyli pytamy się o ilość punktów
                update_b(min(odleglosci1[pole],odleglosci2[pole]),1);             //ze zbioru A które są stricte w mniejszej odległości od centroidu, który jest bliżej punktu ze zbioru B.
                if(odleglosci1[pole]<odleglosci2[pole]){//Następnie uzupełniamy wynik o tej punkty ze zbioru A, które mają tą samą odległość do centroidu znajdującego się bliżej punktu B.
                    wynik=wynik+ile_odleglosci1_a[odleglosci1[pole]];                                                           
                }else{
                    wynik=wynik+ile_odleglosci2_a[odleglosci2[pole]];
                }

                ile_odleglosci1_b[odleglosci1[pole]]++;//Należy też dodać ten punkt w tablicy ile_odleglosci dla przyszłych zapytań.
                if(centroidy.second!=-1){
                    ile_odleglosci2_b[odleglosci2[pole]]++;
                }                                      
                if(powtorzenia[pole]==1){//Musimy również pamiętać o sprawdzeniu powtórzeń.                                         
                    wynik--;
                }
                powtorzenia[pole]=powtorzenia[pole]+1;                            
            }else{                                                                                                    
                wynik=wynik-query_a(0,min(odleglosci1[pole],odleglosci2[pole])-1);//Operacja usunięcia wygląda prawie identycznie, w tym przypadku zmniejszamy wynik i powtorzenia.                 
                update_b(min(odleglosci1[pole],odleglosci2[pole]),-1);//Musimy też pamiętać o usunięciu tego punktu z drzewa przedziałowego oraz tablic ile_odleglosci.
                if(odleglosci1[pole]<odleglosci2[pole]){                                                                        
                    wynik=wynik-ile_odleglosci1_a[odleglosci1[pole]];                                                           
                }else{
                    wynik=wynik-ile_odleglosci2_a[odleglosci2[pole]];
                }                     

                ile_odleglosci1_b[odleglosci1[pole]]--;
                if(centroidy.second!=-1){
                    ile_odleglosci2_b[odleglosci2[pole]]--;
                }      
                if(powtorzenia[pole]==2){//Musimy również pamiętać o sprawdzeniu powtórzeń.                                         
                    wynik++;
                }                                                                                   
                powtorzenia[pole]--;  
            }
        }

        cout<<wynik<<endl;
    }
    //Ostatecznie cały algorytm działa w złożoności O((n+q)*log(n)) ponieważ dodajemy do drzewa wszystkie początkowe punkty zbiorów A i B i wykonujemy q aktualizacji

    return 0;
}
