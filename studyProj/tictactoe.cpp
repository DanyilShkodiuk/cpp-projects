#include <iostream>
using namespace std;

/**
 * Funkcja odpowiada za estetyczne wyświetlenie planszy 3x3 w konsoli.
 * Przyjmuje dwuwymiarową tablicę znaków jako parametr.
 */
void wypiszPlansze(char plansza[3][3]) {
    for (int i = 0; i < 3; i++) {
        cout << "   |   |   " << endl;
        cout << " " << plansza[i][0] << " | " << plansza[i][1] << " | " << plansza[i][2] << endl;
        // Rysowanie linii poziomych (tylko między wierszami)
        if (i < 2) cout << "___|___|___" << endl;
    }
    cout << "   |   |   " << endl;
}

int main() {
    char wybor;

    // Główna pętla programu umożliwiająca wielokrotne rozgrywki [Kryterium: do-while]
    do {
        // Inicjalizacja pustej planszy na początku każdej rundy
        char plansza[3][3] = {
            {' ', ' ', ' '},
            {' ', ' ', ' '},
            {' ', ' ', ' '}
        };

        const char graczX = 'X';
        const char graczO = 'O';
        char terazGra = graczX;
        char zwyciezca = ' ';
        int w = -1, k = -1;

        // Pętla tury gry - maksymalnie 9 ruchów na planszy 3x3
        for (int i = 0; i < 9; i++) {
            wypiszPlansze(plansza);

            // Sprawdzenie, czy gra została rozstrzygnięta w poprzedniej turze. 
            // Jeśli mamy zwycięzcę, przerywamy pętlę przed zapytaniem o kolejny ruch.
            if (zwyciezca != ' '){break;} 

            cout << "Teraz gra: " << terazGra << endl;

            // Pętla walidacji danych wejściowych [Kryterium: obsługa interakcji]
            while (true) {
                cout << "Wprowadz w & k od 0 do 2: ";
                cin >> w >> k;

                // Sprawdzenie czy dane są liczbami oraz czy mieszczą się w zakresie
                if (!cin || w < 0 || w > 2 || k < 0 || k > 2) {
                    cout << "Niepoprawne dane! Podaj liczby od 0 do 2." << endl;
                    cin.clear(); // Wyczyszczenie flagi błędu strumienia
                    cin.ignore(10000, '\n'); // Odrzucenie błędnych znaków z bufora
                }
                // Sprawdzenie czy wybrane pole jest puste
                else if (plansza[w][k] != ' ') {
                    cout << "Pole zajete! Wybierz inne." << endl;
                }
                else break; // Dane poprawne, wyjście z pętli walidacji
            }

            // Zaktualizowanie stanu planszy i zmiana gracza
            plansza[w][k] = terazGra;
            terazGra = (terazGra == graczX) ? graczO : graczX;

            // LOGIKA SPRAWDZANIA WARUNKÓW ZWYCIĘSTWA
            
            // Sprawdzenie wierszy
            for (int r = 0; r < 3; r++){
                if (plansza[r][0] != ' ' && plansza[r][0] == plansza[r][1] && plansza[r][1] == plansza[r][2])
                    zwyciezca = plansza[r][0];
            }

            // Sprawdzenie kolumn
            for (int c = 0; c < 3; c++){
                if (plansza[0][c] != ' ' && plansza[0][c] == plansza[1][c] && plansza[1][c] == plansza[2][c])
                    zwyciezca = plansza[0][c];
            }

            // Sprawdzenie przekątnych (główna i boczna)
            if (plansza[0][0] != ' ' && plansza[0][0] == plansza[1][1] && plansza[1][1] == plansza[2][2]){
                zwyciezca = plansza[0][0];
            }
            if (plansza[0][2] != ' ' && plansza[0][2] == plansza[1][1] && plansza[1][1] == plansza[2][0]){
                zwyciezca = plansza[0][2];
            }
        }

        // KONIEC RUNDY - Wyświetlenie wyników
        wypiszPlansze(plansza);

        if (zwyciezca != ' '){
            cout << "Gracz " << zwyciezca << " wygral!\n";
        }
        else {
            cout << "Remis!\n";
        }

        // Interakcja końcowa - decyzja o kontynuacji
        cout << "Gramy dalej [t/n]: ";
        cin >> wybor;

    } while (wybor == 't' || wybor == 'T');

    return 0;
}