#include <bits/stdc++.h>

using namespace std;

//Przykladowa liczba pierwsza czesto podawana w zadaniach
const long long int M=1e9+7;

long long int szybkie_potegowanie(long long int podstawa, long long int potega){
    //Kiedy potega jest rowna 0 zwracamy 1
    if(potega==0){
        return 1;
    }
    if(potega%2==0){
        //Kiedy potega jest parzysta mozemy ja zmniejszyc dwukrotnie i otrzymany wynik pomnozyc przez samego siebie
        long long int wartosc=szybkie_potegowanie(podstawa,potega/2);
        return (wartosc*wartosc)%M;
    }
    if(potega%2==1){
        //Kiedy potega jest nieparzysta mozemy ja zmniejszyc o 1 i otrzymany wynik pomnozyc przez podstawe
        return (podstawa*szybkie_potegowanie(podstawa,potega-1))%M;
    }
}

int main()
{
    long long int a=325346546,b=98763451;

    cout<<(a%M+b%M)%M;                    //Operacja modulo podczas dodawnia
    cout<<(a%M-b%M+M)%M;                  //Operacja modulo podczas odejmowania
    cout<<((a%M)*(b%M))%M;                //Operacja modulo podczas mnozenia

    long long int odwrotnosc=szybkie_potegowanie(b,M-2);
    cout<<((a%M)*(odwrotnosc%M))%M;       //Operacja modulo podczas dzielenia

    return 0;
}