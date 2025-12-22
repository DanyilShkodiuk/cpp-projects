#include <iostream>
#include <array>
using namespace std;


int main() {
    int N = 7;
    int temperatura[N];
    int suma = 0;
    cout << "Wprowadz 7 losowych temperatur" << endl << endl;
    for (int i = 0; i < N; i++){
        cout << "Temperatura " << i+1 << ": ";
        cin >> temperatura[i];
        suma += temperatura[i];
    }
    cout << endl;
    int srednia = suma / N;
    cout << "Srednia ocen: " << srednia << endl << endl;

    cout << "Wieksza od sredniej: "; 
    for (int i = 0; i < N; i++) {
        if(temperatura[i] > srednia){
            cout << temperatura[i] << " ";
        }
    }
}