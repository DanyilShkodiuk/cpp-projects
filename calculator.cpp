#include <iostream>
#include <limits>
#include <cmath>
using namespace std;

double checkZero(double liczba) {
    while (liczba == 0 || !cin){
        if(!cin) {
            cout << "To nie jest liczba! Podaj liczbe: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> liczba;
            }else if(liczba == 0){
            cout << "Liczba 2 nie moze byc zerem.\nPodaj inna liczbe: ";
            cin >> liczba;
        }
    }
    return liczba;
}

int main() {

    cout << "*****************************\n";
    cout << "KALKULATOR\n";
    cout << "*****************************\n";

    double liczba1, liczba2, resultat;
    char operacja;

        cout << "Podaj pierwsza liczbe: ";
        while (!(cin >> liczba1)) { 
            cout << "To nie jest liczba! Podaj jeszcze raz: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Podaj druga liczbe: ";
        while (!(cin >> liczba2)) { 
            cout << "To nie jest liczba! Podaj jeszcze raz: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        
        while (true) {

        cout << "Podaj operacje (+ - * / %, q -> exit): ";
        cin >> operacja;

        if(operacja == 'q' || operacja == 'Q') {
            cout << "Koniec"<< endl;
            break;
        }

        bool poprawnaOperacja = true;

        switch (operacja) {
            case '+':
                resultat = liczba1 + liczba2;break;

            case '-':
                resultat = liczba1 - liczba2;break;
            
            case '*':
                resultat = liczba1 * liczba2;break;

            case '/':
                liczba2 = checkZero(liczba2);
                resultat = liczba1 / liczba2;
                break;
            

            case '%':
                liczba2 = checkZero(liczba2);
                resultat = fmod(liczba1,liczba2);
                break;
            break;

            default:
                cout << "Nieznana operacja!\n";
                poprawnaOperacja = false;
                break;
        }
        if(poprawnaOperacja) {
            cout << "Resultat: " << resultat << endl;
        }
    }
}