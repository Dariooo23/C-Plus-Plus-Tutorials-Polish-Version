#include <bits/stdc++.h>

using namespace std;

long long int n,m,wynik=0;

//Grafy
vector<vector<pair<long long int,long long int>>> graf_odleglosci;

//Tablice do zapytan i aktualizacji
vector<vector<long long int>> odleglosci_centroidalne;
vector<pair<long long int,long long int>> sumy_centroidow;
vector<long long int> rodzice_centroidow;
vector<long long int> poziom_centroidow;
vector<long long int> ilosc_zamkow;

//Tablice do dekompozycjy
vector<long long int> rozmiar_poddrzew;
vector<bool> uzyte;

void oblicz_poddrzewa(long long int s,long long int p)
{
    rozmiar_poddrzew[s]=1;
    for(pair<long long int,long long int> &v :graf_odleglosci[s])
    {
        if(v.first!=p && uzyte[v.first]==0)
        {
            oblicz_poddrzewa(v.first,s);
            rozmiar_poddrzew[s]=rozmiar_poddrzew[s]+rozmiar_poddrzew[v.first];
        }
    }
}

void oblicz_odleglosci_centroidalne(long long int s,long long int p,long long int poziom){
    for(pair<long long int,long long int> &v :graf_odleglosci[s])
    {
        if(v.first!=p && uzyte[v.first]==0)
        {
            odleglosci_centroidalne[poziom][v.first]=odleglosci_centroidalne[poziom][s]+v.second;
            oblicz_odleglosci_centroidalne(v.first,s,poziom);
        }
    }
}

long long int findCent(long long int w,long long int parent,long long int n)
{
    for(pair<long long int,long long int> &v : graf_odleglosci[w])
    {
        if(uzyte[v.first]==0 && v.first!=parent)
        {
             if(rozmiar_poddrzew[v.first]>n/2)
             {
                return findCent(v.first,w,n);
             }
        }
    }
    return w;
}

void decompose(long long int w,long long int rodzic,long long int poziom)
{
    oblicz_poddrzewa(w,-1);

    long long int c=findCent(w,-1,rozmiar_poddrzew[w]);
    rodzice_centroidow[c]=rodzic;
    poziom_centroidow[c]=poziom;
    uzyte[c]=1;

    oblicz_odleglosci_centroidalne(c,0,poziom);

    for(pair<long long int ,long long int> &v : graf_odleglosci[c])
    {
        if(uzyte[v.first]==0)
        {
            decompose(v.first,c,poziom+1);
        }
    }
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;

    odleglosci_centroidalne.resize(22,vector<long long int> (n+9,0));
    sumy_centroidow.resize(n+9,{0,0});
    rodzice_centroidow.resize(n+9,0);
    poziom_centroidow.resize(n+9,0);
    rozmiar_poddrzew.resize(n+9);
    graf_odleglosci.resize(n+9);
    ilosc_zamkow.resize(n+9,0);
    uzyte.resize(n+9,0);

    for(int i=1;i<n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        graf_odleglosci[a].push_back({b,c});
        graf_odleglosci[b].push_back({a,c});
    }

    rodzice_centroidow[1]=0;
    decompose(1,0,1);

    int zamekg=1,zamek=1; 
    zamek=zamekg;
    while(zamek!=0){
        ilosc_zamkow[zamek]=ilosc_zamkow[zamek]+1;
        sumy_centroidow[zamek].first=sumy_centroidow[zamek].first+odleglosci_centroidalne[poziom_centroidow[zamek]][zamekg];
        sumy_centroidow[zamek].second=sumy_centroidow[zamek].second+odleglosci_centroidalne[poziom_centroidow[rodzice_centroidow[zamek]]][zamekg];
        zamek=rodzice_centroidow[zamek];
    }

    for(int i=1;i<=m;i++){
        cin>>zamekg;

        zamek=zamekg;
        wynik=wynik+sumy_centroidow[zamek].first;
        while(rodzice_centroidow[zamek]!=0){
            wynik=wynik+(ilosc_zamkow[rodzice_centroidow[zamek]]-ilosc_zamkow[zamek])*odleglosci_centroidalne[poziom_centroidow[rodzice_centroidow[zamek]]][zamekg]+sumy_centroidow[rodzice_centroidow[zamek]].first-sumy_centroidow[zamek].second;
            zamek=rodzice_centroidow[zamek];
        }   
        zamek=zamekg;
        while(zamek!=0){
            ilosc_zamkow[zamek]=ilosc_zamkow[zamek]+1;
            sumy_centroidow[zamek].first=sumy_centroidow[zamek].first+odleglosci_centroidalne[poziom_centroidow[zamek]][zamekg];
            sumy_centroidow[zamek].second=sumy_centroidow[zamek].second+odleglosci_centroidalne[poziom_centroidow[rodzice_centroidow[zamek]]][zamekg];
            zamek=rodzice_centroidow[zamek];
        }

        cout<<wynik*2<<endl;
    }

    return 0;
}
