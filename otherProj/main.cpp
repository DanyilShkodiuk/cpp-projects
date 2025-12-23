#include <iostream>
#include <limits>
#include <map>

using namespace std;

int main() {
    int N;
    cout << "Ile ocen chcesz wprowadzic? (2-5): ";
    while (!(cin >> N) || N < 2 || N > 5) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Zly input. Podaj liczbe calkowita z przedzialu 2-5: ";
    }

    int* oceny = new int[N];
    for (int i = 0; i < N; ++i) {
        cout << "Ocena " << i+1 << ": ";
        while (!(cin >> oceny[i])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Niepoprawne dane. Podaj liczbe calkowita: ";
        }
    }

    map<int,int> counts;
    for (int i = 0; i < N; ++i) ++counts[oceny[i]];

    cout << "\nWprowadzone oceny: ";
    for (int i = 0; i < N; ++i) cout << oceny[i] << " ";

    cout << "\n\nHistogram (gwiazdki = liczba wystapien):\n";
    for (const auto& p : counts) {
        cout << p.first << ": ";
        for (int k = 0; k < p.second; ++k) cout << '*';
        cout << " (" << p.second << ")\n";
    }

    delete[] oceny;
    oceny = nullptr;
    return 0;
}