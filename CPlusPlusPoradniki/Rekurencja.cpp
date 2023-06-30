#include <bits/stdc++.h>

using namespace std;

//Funkcja obliczajaca Ciag Fibonacciego w czasie wykladniczym rekurencyjnie
int fib_wolno(int n){
    if(n==0 || n==1){
        return n;
    }else{
        return fib_wolno(n-1)+fib_wolno(n-2);
    }
}

//Tworzymy tablice do zapamietywania
int zapamietywanie[1000000];
//Funkcja obliczajaca Ciag Fibonacciego w czasie liniowym rekurencyjnie
int fib_szybko(int n){
    if(n==0 || n==1){
        return n;
    }else{
        zapamietywanie[n]=fib_szybko(n-1)+fib_szybko(n-2);
        return zapamietywanie[n];
    }
}

//Funkcja obliczajaca Ciag Fibonacciego w czasie liniowym iteracyjnie
int fib_szybko_it(int n){
    int liczba1=0,liczba2=1;
    for(int i=1;i<=n;i++){
        if(i%2==0){
            liczba1=liczba1+liczba2;
        }else{
            liczba2=liczba2+liczba1;
        }
    }
    if(n%2==0){
        return liczba1;
    }else{
        return liczba2;
    }
}
int main()
{
    std::ios_base::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0); 

    int n;
    cin>>n;

    cout<<fib_wolno(n)<<endl;
    cout<<fib_szybko(n)<<endl;
    cout<<fib_szybko_it(n)<<endl;
    return 0;
}
