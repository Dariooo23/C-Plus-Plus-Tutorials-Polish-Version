//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int n,m,k;
long long int wynik;
vector<int> visited;
vector<vector<int>> graf;
vector<long long int> fotogenicznosc;

void dfs(int s){
    visited[s]=1;
    wynik=wynik+fotogenicznosc[s];
   
    for(const int &v:graf[s]){
        if(visited[v])continue;
        dfs(v);
    }return;
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    cin>>n>>m>>k;

    graf.resize(n+1);
    fotogenicznosc.resize(n+1);

    for(int i=1;i<=n;i++){      //Wczytujemy fotogeniczność polanek.
        cin>>fotogenicznosc[i];
    }
    for(int i=1;i<=n;i++){      //Wczytujemy graf
        int a,b;
        cin>>a>>b;
        graf[a].push_back(b);
    }

    for(int i=1;i<=n;i++){      //Dla każdego punktu obliczamy jego finalną fotogeniczność rozchodząc się po całym grafie  
        visited.resize(n+1);    //i sumując fotogeniczność wszystkich punktów do których możemy dojść z punktu początkowego.
        wynik=0;                //Za każdym razem czyścimy tablicę visited (Dla każdego przejścia grafu potrzebujemy ponownie odwiedzać niektóre punkty)
        dfs(i);
        visited.clear();
        cout<<wynik<<endl;
    }

    return 0;
}
 