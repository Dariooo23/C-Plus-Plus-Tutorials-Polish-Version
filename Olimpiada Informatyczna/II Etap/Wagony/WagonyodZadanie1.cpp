//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<unsigned long long int> dp;

long long int funkcja(long long int i,long long int j,long long int a,long long int b){ //Funkcja ta zachowuje się zbyt chaotycznie
    return (i*a+j*b)%1001;                                                              //pozostaję więc programowanie dynamiczne.
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int n,d,a,b;  
    cin>>n>>d>>a>>b;

    dp.resize(n+1,1e18);

    dp[1]=0; //Ustalamy stany początkowe pociąg o długości 1 (Tym bardziej też 0) da się uzyskać kosztem 0.
             //Wzór zastosowany w tym programowaniu dynamicznym bierze się stąd, że aby stowrzyć każdy wagon należy doliczyć wartość z funkcji 
             //oraz koszty stworzenia dwóch poprzednich długości pociągów.
             
    for(long long int i=2;i<=n;i++){                                                    //Obliczamy dla każdego n najmniejszy koszt jego uzyskania.
        for(long long int j=max((i-d-1)/2+1,(long long int)1);j<=min((i+d)/2,n);j++){   //Każdy stan dp[i] jest ograniczony przez warunek
            dp[i]=min((dp[j]+dp[i-j]+funkcja(j,i-j,a,b)),dp[i]);                        //gdzie różnica długości scalanych wagonów nie może
        }                                                                               //być większy niż d.
    }

    cout<<dp[n];  //Złożoność czasowa O(n*d), dla każdego n bierzemy minimum z d innych stanów.
    return 0;
}
 
