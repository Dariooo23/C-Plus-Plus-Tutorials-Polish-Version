#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mapa_przekasek;
vector<vector<int>> mapa_weza;
vector<int> waz;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    int rozmiar,przekaski,zapytania,czas=1,x,y,rozmiarweza=1;
    cin>>rozmiar>>przekaski>>zapytania;

    mapa_przekasek.resize(rozmiar+9,vector<int> (rozmiar+9,-1));
    mapa_weza.resize(rozmiar+9,vector<int> (rozmiar+9,-1));

    pair<int,int> glowa={1,1};
    mapa_weza[1][1]=1;
    waz.push_back(0);

    for(int i=1;i<=przekaski;i++){
        int kolor;
        cin>>x>>y>>kolor;
        mapa_przekasek[x][y]=kolor;
    }

    for(int i=1;i<=zapytania;i++){
        char polecenie;
        cin>>polecenie;
        if(polecenie=='Z'){
            cin>>x>>y;
            if(mapa_weza[x][y]==-1){
                cout<<-1<<endl;
            }else{
                if((rozmiarweza-(czas-mapa_weza[x][y])-1)<0){
                    cout<<-1<<endl;
                }else{
                    
                    cout<<waz[(rozmiarweza-(czas-mapa_weza[x][y])-1)]<<endl;
                }
            }
        }else
        if(polecenie=='D'){
            glowa.first++;
            czas++;
            if(mapa_przekasek[glowa.first][glowa.second]!=-1){
                waz.push_back(mapa_przekasek[glowa.first][glowa.second]);
                rozmiarweza++;
                mapa_przekasek[glowa.first][glowa.second]=-1;
                mapa_weza[glowa.first][glowa.second]=czas;
            }else{
                mapa_weza[glowa.first][glowa.second]=czas;
            }
        }else
        if(polecenie=='G'){
            glowa.first--;
            czas++;
            if(mapa_przekasek[glowa.first][glowa.second]!=-1){
                waz.push_back(mapa_przekasek[glowa.first][glowa.second]);
                rozmiarweza++;
                mapa_przekasek[glowa.first][glowa.second]=-1;
                mapa_weza[glowa.first][glowa.second]=czas;
            }else{
                mapa_weza[glowa.first][glowa.second]=czas;
            }
        }else
        if(polecenie=='P'){
            glowa.second++;
            czas++;
            if(mapa_przekasek[glowa.first][glowa.second]!=-1){
                waz.push_back(mapa_przekasek[glowa.first][glowa.second]);
                rozmiarweza++;
                mapa_przekasek[glowa.first][glowa.second]=-1;
                mapa_weza[glowa.first][glowa.second]=czas;
            }else{
                mapa_weza[glowa.first][glowa.second]=czas;
            }
        }else
        if(polecenie=='L'){
            glowa.second--;
            czas++;
            if(mapa_przekasek[glowa.first][glowa.second]!=-1){
                waz.push_back(mapa_przekasek[glowa.first][glowa.second]);
                rozmiarweza++;
                mapa_przekasek[glowa.first][glowa.second]=-1;
                mapa_weza[glowa.first][glowa.second]=czas;
            }else{
                mapa_weza[glowa.first][glowa.second]=czas;
            }
        }
    }

    
    return 0;
}
 
