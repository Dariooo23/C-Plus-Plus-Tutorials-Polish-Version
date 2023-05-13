#include <bits/stdc++.h>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int a=3,b=7;
    cout<<a+b<<endl; //Operacja dodawania, wynik to 10
    cout<<a-b<<endl; //Operacja odejmowania, wynik to -4;
    cout<<a*b<<endl; //Operacja mnożenia, wynik to 21
    cout<<a/b<<endl; //Operacja dzielenia, wynik to 0, dzieję się tak ze względu na typ zmiennych int
    cout<<b%a<<endl; //Operacja modulo, wynik to 1

    long double d=10,e=3;
    cout<<d/e<<endl; //Operacja dzielenia, wynik to 3,33333, dzieję się tak ze względu na typ zmiennych long double


    int f=2,g=5;
    f++;
    cout<<f<<endl; //Zwiększyliśmy wartość f o 1, wynik to 3
    g--;
    cout<<g<<endl; //Zmniejszyliśmy wartość g o 1, wynik to 4


    cout<<sqrt(b)<<endl; //Operacja pierwiastkowania, wynik to 2.64575, 
                         //jednak jeżeli przypiszemy ten wynik do zmiennej całkowitej to otrzymamy 2
    cout<<pow(b,a)<<endl;//Operacja potegowania, wynik to 7 do potęgi 3 czyli 343

    return 0;
}
 
