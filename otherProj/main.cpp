#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void validacjaHasla(string& haslo) {
    bool isUpper = false;
    bool isLower = false;
    bool isDigit = false;

    for (char znak : haslo) {
        if(isupper(znak)) {isUpper = true;}
        if(islower(znak)) {isLower = true;}
        if(isdigit(znak)) {isDigit = true;}
    }

    if(!isUpper) {
        cout << "Blad: Nie ma duzej litery!" << endl;
    }
    if(!isLower) {
        cout << "Blad: Nie ma malej litery!" << endl;
    }
    if(!isDigit) {
        cout << "Blad: Niem ma liczb!" << endl;
    }
    if(haslo.length() < 8){
        cout << "Blad: Haslo za krotkie! wprowadz minimum 8 znakow." << endl;
    }
    if(isUpper && isLower && isDigit && haslo.length() >= 8) {
        cout << "Haslo poprawne!" << endl;
    }
}

int main() {
    string haslo;    
    while (haslo != "q" && haslo != "Q")
    {
        cout << "Podaj haslo: ";
        cin >> haslo;
        validacjaHasla(haslo);
    };
    cout << "\n Wyjscie z programu\n";
}