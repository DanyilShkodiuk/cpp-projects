#include <iostream>
#include <array>
using namespace std;


int main() {
    const int N = 10;
    int tablica[N];
    
    for(int i = 0; i < N; i++) {
        cout << "Podaj liczbe nr " << i+1 << ": ";
        cin >> tablica[i];
    }

    cout <<"Tablica: ";
    for(int i =0; i < N; i++) {
        cout << tablica[i] << " ";
    }
    
    int max_val = tablica[0];
    int min_val = tablica[0];

    for(int i = 1; i < N; i++) {
        if(tablica[i] > max_val) max_val = tablica[i];
        if(tablica[i] < min_val) min_val = tablica[i];
    }

    cout << "\nMax: " << max_val << endl;
    cout << "Min: " << min_val << endl;
}