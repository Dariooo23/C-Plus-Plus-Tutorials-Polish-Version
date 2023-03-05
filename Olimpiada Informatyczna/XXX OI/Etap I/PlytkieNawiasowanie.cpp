//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

vector<char> nawiasowanie;
vector<long long int> prefiksy;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    long long int dlugosc,glebokosc,wynik=0,odejmij=0;
    cin>>dlugosc>>glebokosc;
    
    nawiasowanie.resize(dlugosc+1);
    prefiksy.resize(dlugosc+1);
    prefiksy[0]=0;

    for(int i=1;i<=dlugosc;i++){
        cin>>nawiasowanie[i];
    }
    for(int i=1;i<=dlugosc;i++){
        if(nawiasowanie[i]=='('){
            prefiksy[i]=prefiksy[i-1]+1;
        }
        else{
            prefiksy[i]=prefiksy[i-1]-1;
        }
    }

    for(int i=1;i<=dlugosc;i++){
        prefiksy[i]=prefiksy[i]-odejmij;
        if(prefiksy[i]>glebokosc){
            odejmij=odejmij+2;
            wynik++;
        }
        if(prefiksy[i]<0){
            odejmij=odejmij-2;
            wynik++;
        }
    }
    
    cout<<wynik; 
    return 0;
}
 