#include <iostream>
#include <string>
using namespace std;

main(){
    //zapisanie prawidłego hasła
    string poprawne_haslo = "tajne123";
    string haslo;
    int proba = 0;

    //wchodzimy w program
    do{
        //zapytanie o hasło
        cout << "Podaj haslo (3 proby): ";
        //user podaje hasło
        cin >> haslo;
        //Walidacja -> haslo == poprawne_haslo : "zalogowany" ? "zle haslo"; proba++;
        if(haslo == poprawne_haslo){
            cout << "Zostales zalogowany! :D";
            break;
        } else {
            cout << "Zle haslo." << "\nProby: " << proba + 1 << endl;
            proba++;
        }
    }while (proba < 3);
    cout << "Limit prob zostal wykorzystany";
}