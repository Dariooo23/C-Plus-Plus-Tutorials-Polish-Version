//Karol Dziekan
#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);

    //Roznie przyklady par z uzyciem struktury pair
    //Aby przypisać jakas wartosc obu zmiennym w parze jednoczesnie nalezy uzyc {}.
    pair<int,int> para1={1,10};
    pair<long double,float> para2={12.34,56};
    pair<float,string> para3={0.55,"abc"};
    pair<char,short int> para4={'a',12};
    

    //Mozna jednak przypisywac wartosc pojedycznym zmiennym
    pair<int,int> para5;
    para5.first=5;
    para5.second=10;

    //Jezeli chcemy wypisac pare, musimy wskazac dokladnie ktora zmienna chcemy wypisac
    cout<<para1.first<<" "<<para1.second<<endl;

    int n=50;
    //Mozemy ustawic rozmiar vectora od razu na poczatku jego tworzenia
    vector<int> tab1(n);
    vector<vector<int>> tab2(n,vector<int> (n));


    //Lub tez pozniej w trakcie programu
    vector<int> tab3;
    tab3.resize(n);

    //W vectorze zapisujemy i odczytujemy wartosci na indeksach jak w normalnej tablicy.
    for(int i=0;i<n;i++){
        tab3[i]=i;
    }

    //Mozemy rowniez wrzucac wartosci na koniec tablicy jezeli nie chcemy ustawiac jej rozmiaru
    vector<int> tab4;
    for(int i=0;i<n;i++){
        tab4.push_back(i);
    }

    //Mozemy odczytac jaki jest rozmiar tablicy jezeli chcemy ja cala wypisac od poczatku do konca
    for(int i=0;i<tab4.size();i++){
        cout<<tab4[i]<<" ";
    }
    return 0;
}