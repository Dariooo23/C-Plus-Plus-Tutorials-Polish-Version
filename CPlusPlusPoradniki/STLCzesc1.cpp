#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a=10,b=35;

    cout<<min(a,b)<<endl; //Zwraca mniejsza wartosc;
    cout<<max(a,b)<<endl; //Zwraca wieksza wartosc;


    int tab[8]={1,5,12,5,23,4,8,9};
    sort(tab,tab+8); //Sortuje tablice rosnaco
    for(int i=0;i<8;i++){
        cout<<tab[i]<<" ";
    }cout<<endl;


    cout<<gcd(a,b)<<endl; //Zwraca najwiekszy wspolny dzielnik


    next_permutation(tab,tab+8); //Zamienia aktualna tablice na jej kolejna permutacje
    for(int i=0;i<8;i++){
        cout<<tab[i]<<" ";
    }cout<<endl;


    prev_permutation(tab,tab+8); //Zamienia aktualna tablice na jej poprzednia permutacje
    for(int i=0;i<8;i++){
        cout<<tab[i]<<" ";
    }cout<<endl;


    random_shuffle(tab,tab+8);   //Zamienia aktuialna tablice na jej losowa permutacje
    for(int i=0;i<8;i++){
        cout<<tab[i]<<" ";
    }cout<<endl;
    return 0;
}
