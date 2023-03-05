#include <bits/stdc++.h>

using namespace std;

vector<int> lista1(400000);
vector<int> lista2(400000);
vector<int> sufiksy(400000);
vector<int> prefiksy(400000);
vector<vector<int>> pozycje(400000);

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int dlugosc1,dlugosc2,rodzaje;
    cin>>dlugosc1>>dlugosc2>>rodzaje;

    prefiksy[0]=0;
    sufiksy[dlugosc1+1]=0;

    for(int i=1;i<=dlugosc1;i++){
        cin>>lista1[i];
    }
    for(int i=1;i<=dlugosc2;i++){
        cin>>lista2[i];
        pozycje[lista2[i]].push_back(i);
    }

    int wskaznik1=1,wskaznik2=1;
    while(wskaznik1<=dlugosc1){
        if(wskaznik2>dlugosc2){
            if(wskaznik1<350000){
                wskaznik1++;
            }
            prefiksy[wskaznik1]=prefiksy[wskaznik1-1];
        }
        if(lista1[wskaznik1]==lista2[wskaznik2]){
            prefiksy[wskaznik1]++;
            if(wskaznik1<350000){
                wskaznik1++;
            }
            if(wskaznik1<350000){
                wskaznik2++;
            }
        }else{
            if(wskaznik1<350000){
                wskaznik1++;
            }
        }
        prefiksy[wskaznik1]=prefiksy[wskaznik1]+prefiksy[wskaznik1-1];
    }

    wskaznik1=dlugosc1,wskaznik2=dlugosc2;
    while(wskaznik1>=1){
        if(wskaznik2<=1){
            if(wskaznik1!=0){
                wskaznik1--;
            }
            sufiksy[wskaznik1]=sufiksy[wskaznik1+1];
        }
        if(lista1[wskaznik1]==lista2[wskaznik2]){
            sufiksy[wskaznik1]++;
            if(wskaznik1!=0){
                wskaznik1--;
            }
            if(wskaznik2!=0){
                wskaznik2--;
            }
        }else{
            if(wskaznik1!=0){
                wskaznik1--;
            }
        }
        sufiksy[wskaznik1]=sufiksy[wskaznik1]+sufiksy[wskaznik1+1];
    }
    
   
    for(int i=1;i<=dlugosc1;i++){
        int poczatek=dlugosc2-sufiksy[i];
        int koniec=prefiksy[i];

        cout<<poczatek<<" "<<koniec<<endl;
        int lewo=0,prawo=pozycje[lista1[i]].size()-1,srodek;
        if(pozycje[lista1[i]].size()==0){
            cout<<"0"<<" ";
            continue;
        }

        while(lewo<prawo){
            srodek=(lewo+prawo)/2;
            if(pozycje[lista1[i]][srodek]<poczatek){
                lewo=srodek+1;
            }else{
                prawo=srodek;
            }
        }
        
        if(lewo>=pozycje[lista1[i]].size()){
            cout<<"0"<<" ";
            continue;
        }
        if(pozycje[lista1[i]][lewo]<poczatek || pozycje[lista1[i]][lewo]>koniec){
            cout<<"0"<<" ";
        }else{
            cout<<"1"<<" ";
        }
    }


    return 0;
}
