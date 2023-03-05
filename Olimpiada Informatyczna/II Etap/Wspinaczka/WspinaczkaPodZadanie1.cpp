#include <bits/stdc++.h>

using namespace std;

int n,m,k;
vector<int> visited;
vector<long long int> dp;
vector<vector<int>> graf;
vector<long long int> fotogenicznosc;

long long int dfs(int s){
    visited[s]=1;
    dp[s]=fotogenicznosc[s];

    for(const int &v:graf[s]){
        if(visited[v])continue;
        dp[s]=dp[s]+dfs(v);
    }

    return dp[s];
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>m>>k;

    dp.resize(n+1);
    graf.resize(n+1);
    visited.resize(n+1);
    fotogenicznosc.resize(n+1);

    for(int i=1;i<=n;i++){      //Wczytujemy fotogeniczność polanek.
        cin>>fotogenicznosc[i];
    }
    for(int i=1;i<=m;i++){      //Wczytujemy graf (Który jest drzewem).
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
    }

    for(int i=1;i<=n;i++){       //Dla każdego nieodwiedzonego punktu wywołujemy dfs() i obliczamy fotogeniczność jaką uzyskamy dla niego
        if(visited[i])continue;  //poprzez zsumowanie fotogeniczności wszystkich synów i jego samego.
        dfs(i);                  //Cała pętla z funkcją działa w czasie O(n) ponieważ każdy punkt zostanie odwiedzony tylko raz.
    }

    for(int i=1;i<=n;i++){       //Na koniec wypisujemy odpowiedzi dla wszystkich punktów.
        cout<<dp[i]<<endl;       //Program ma złożoność czasową O(n), wczytujemy graf, obliczamy wyniki i je wypisujemy wszystko w czasie O(n).
    }

    return 0;
}
 
