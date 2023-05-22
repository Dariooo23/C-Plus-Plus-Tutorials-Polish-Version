#include <bits/stdc++.h>

using namespace std;

int main()
{
    //W kodzie pojawia się "cout" oraz "endl", pierwsze z nich służy do wypisania dowolnej rzeczy w konsoli, natomiast drugie służy za znak nowej lini
    //Czyli jeżeli napiszemy "cout<<3;" to w konsoli otrzymamy "3", a jeżeli napiszemy "cout<<3<<endl;" to otrzymamy "3" oraz nasz kursor przeskoczy do nowej lini



    //Pierwszy sposób zapisu instrukcji warunkowej 
    if(true){
        cout<<"prawda";
    }else{
        cout<<"falsz";
    }
    cout<<endl;

    //Drugi sposób zapisu instrukcji warunkowej
    (false) ? cout<<"prawda" : cout<<"falsz";
    cout<<endl;




    //Pierwszy sposób zapisu pętli for
    for(int i=0;i<100;i++){
        cout<<i<<" ";            //Pętla wypisze wszystkie liczby od 0 do 99
    }
    cout<<endl;

    //Drugi sposób zapisu pętli for
    int tablica[100]; //Ten rodzaj pętli sprawdza całą strukturę przechodząc po kolei każdy indeks
                      //Potrzebujemy więc do niej tablice, ich dokładniejsze omówienie będzie w kolejnym poście.
    for(int i=0;i<100;i++){//Ustawiam każdy indeks tablicy na wartość 0.
        tablica[i]=0;
    }
    for(int v : tablica){
        cout<<v<<" "; //Tym razem zmienna v nie jest indeksem jak w pierwszym przypadku zmienna "i", tylko jest samą wartością z danego indeksu tablicy
    }            //Pętla wypisze więc 100 razy "0", ponieważ cała tablica którą stworzyliśmy jest pusta.
    cout<<endl;




    //Pierwszy sposób zapisu pętli while
    int a=0;
    while(a>0){ //Pętla nie wypiszę nic ponieważ najpierw sprawdza warunek "a>0", a dopiero później wykonuję instrukcję.
        a--;
        cout<<a<<" ";
    }
    cout<<endl;

    //Drugi sposób zapisu pętli while
    int b=0;
    do{         //Pętla wypiszę -1 ponieważ najpierw wykonuje instrukcję, a dopiero później sprawdza warunek "b>0"
        b--;
        cout<<b<<" ";
    }while(b>0);
    cout<<endl;

    return 0;
}
 