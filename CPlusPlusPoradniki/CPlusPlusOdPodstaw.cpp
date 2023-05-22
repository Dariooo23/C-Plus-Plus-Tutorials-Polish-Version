
#include <bits/stdc++.h> // <---- Biblioteki dołączane do programu

using namespace std; // <---- Przestrzeń nazw

void funkcja1(int liczba){ // <---- Przykładowa funkcja

    return;
}
int funkcja2(string slowo, int liczba){ // <---- Przykładowa funkcja

    return liczba-10;
}
string funkcja3(char znak, long double liczba){ // <---- Przykładowa funkcja
    string slowo;

    return slowo;
}

int main() // <---- Funkcja main od której zaczyna się cały program
{   
    //W kodzie pojawia się "cout" oraz "endl", pierwsze z nich służy do wypisania dowolnej rzeczy w konsoli, natomiast drugie służy za znak nowej lini
    //Czyli jeżeli napiszemy "cout<<3;" to w konsoli otrzymamy "3", a jeżeli napiszemy "cout<<3<<endl;" to otrzymamy "3" oraz nasz kursor przeskoczy do nowej lini;
    
    bool liczba0=0; //Wartości 0 lub 1
    int liczba1=0; //Wartości od -2147483648 do 2147483647 w liczbach całkowitych
    unsigned int liczba2; //Wartości od 0 do 4294967295 w liczbach całkowitych
    long long int liczba3=0; // Wartości od -9223372036854775808 do 9223372036854775807 w liczbach całkowitych
    float liczba4=0; // Wartości od 1.175494351*10^-38 do 3.402823466*10^38 w liczbach rzeczywistych
    double liczba5=0; // Wartości od 2.2250738585072014*10^-308 do 1.7976931348623158*10^308 w liczbach rzeczywistych
    long double liczba6=0; // Wartości od 2.2250738585072014*10^-308 do 1.7976931348623158*10^308 w liczbach rzeczywistych
    char znak='a'; // Jedna wartość z tablicy ASCII
    string slowo="abcd"; // Wiele wartości z tablicy ASCII

    
    //Jeżeli chcemy wywołać jakąś funkcję wystarczy że napiszemy jej nazwę oraz wprowadzimy potrzebne zmienne
    funkcja1(10);
    
    int a=funkcja2("abcd",25);
    cout<<a<<endl;
    
    cout<<funkcja3('z',4.5)<<endl;
    
    return 0;
}
 
