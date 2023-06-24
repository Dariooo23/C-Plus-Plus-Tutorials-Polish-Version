#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x,y,a,b;
    cin>>x>>y;
    //W "x" i "y" zapisujemy oryginalne liczby, dla następnych algorytmów będziemy je kopiować do zmienny "a" i "b"

    //NWD(Wolno)
    a=x;
    b=y;
    while(b!=a){
        if(a<b){
            b=b-a;
        }else{
            a=a-b;
        }
    }
    cout<<"NWD (Wolno): "<<a<<endl;

    //NWD(Szybko)
    a=x;
    b=y;
    int p;
    while(b!=0){
        p=b;
        b=b%a;
        a=p;
    }
    cout<<"NWD (Szybko): "<<a<<endl;

    //NWW
    //W zmiennej "a" znajduję się NWD(a,b) dlatego zamiast dzielić przez NWD(a,b) dzielimy przez "a"
    cout<<"NWW: "<<(x*y)/a<<endl;
    return 0;
}
