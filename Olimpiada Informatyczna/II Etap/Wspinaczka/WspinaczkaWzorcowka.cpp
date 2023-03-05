//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> graf;
vector<vector<long long int>> dp;
vector<long long int> fotogenicznosc;

void oblicz_dp(){
    //Obliczamy stany dp od n do 1, ponieważ dla każdej polanki będziemy potrzebować stanów
    //z polanek tylko od niej większych, więc je musimy obliczyć wcześniej.
    for(int i=n;i>=1;i--){
        //Dla każdej polanki przeglądamy wszystkie możliwe kombinacje polanek.
        for(int j=0;j<(2<<k);j++){

            //Jeżeli pierwszy bit maski bitowej "j" nie jest zapalony to przenosimy wartość z dp od punktu wyżej.
            //Możemy zauważyć że maska bitowa "j>>1" tyczy się tych polanek co maska bitowa "j", oprócz polanki "i"
            //ale ona nie jest brana pod uwagę (pierwszy bit maski bitowej nie jest zapalony)
            //oraz maska bitowa "j>>1" bierzę pod uwagę polankę "i+k+1" ale jej też nie bierzemy pod uwagę 
            //(Nie jest spełniony warunek, gdzie odległość między punktami wynosi maksymalnie k).
            if(!(j&1)){
                dp[i][j]=dp[i+1][(j>>1)];
            }else{
            //Jeżeli pierwszy bit maski bitowej "j" jest zapalony to wartość dla dp[i][j] jest dp dla polanki wyżej 
            //maski bitowej "j>>1" (Wyjaśnienie jak wyżej) oraz dodajemy do tego polanki, do których możemy się dostać 
            //z polanki "i" oraz samą fotogeniczność polanki "i" ponieważ w tym wypadku jest brana pod uwagę 
            //(pierwszy bit maski bitowej jest zapalony).
                dp[i][j]=dp[i+1][((j>>1)|graf[i])]+fotogenicznosc[i];
            }
        }
    }
    return;
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    //Wczytujemy ilość polanek, dróg oraz maksymalną długość ścieżki.
    cin>>n>>m>>k; 

    //Ustawiamy odpowiednie rozmiary vectorów
    //Vector graf przetrzymuje dla każdej polanki (Których jest n) do jakich innych polanek można dojść.
    graf.resize(n+1,0);        
    //Vector fotogenicznosc przetrzymuje dla każdej polanki (Których jest n) ich fotogeniczność.
    fotogenicznosc.resize(n+10);
    //Vector dp przetrzymuje dla każdej polanki (Których jest n) 2 do potęgi k stanów
    //ponieważ tyle jest maksymalnie sposobów wyboru podzbioru punktów ze zbioru o rozmiarze k.
    dp.resize(n+10,vector<long long int> ((2<<k)+10,0));

    //Wczytujemy fotogeniczności polanek.
    for(int i=1;i<=n;i++){
        cin>>fotogenicznosc[i];
    }

    //Tym razem będziemy zapisywać sąsiadów każdej polanki w nietypowy sposób.
    //Nie będzie to vector, jak w większości przypadków, a maska bitowa 
    //czyli każdy zbiór sąsiadów dla danej polanki będzie reprezentowany przez liczbę.
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;

        //W zależności od tego o ile jest oddalona polanka "b" od polanki "a", to taką potęge 2 będziemy dodawać do sumy.
        //Przykładowo dodając do polanki 4 polankę 9, musimy dodać do sumy graf[4] wartość 1<<(9-4-1) aby zapalić 5 bit.
        //"-1" bierze się stąd, że 1 sama w sobie bez przesunięcia bitowego ma zapalony pierwszy bit w swoim zapisie binarnym.
        graf[a]=graf[a]+(1<<(b-a-1));
    }

    //Po wczytaniu wszystkiego, obliczamy dp.
    oblicz_dp();

    //Wszystkie odpowiedzi dla każdej polany znajdują się w masce bitowej uwzględniającej tylko ten punkt.
    for(int i=1;i<=n;i++){
        cout<<dp[i][1]<<endl;
    }

    return 0;
}
 