#include <iostream>
using namespace std;

void wypiszPlansze(char plansza[3][3]) {
    for (int i = 0; i < 3; i++) {
        cout << "   |   |   " << endl;
        cout << " " << plansza[i][0] << " | " << plansza[i][1] << " | " << plansza[i][2] << endl;
        if (i < 2) cout << "___|___|___" << endl;
    }
    cout << "   |   |   " << endl;
}

int main() {
    char wybor;

    do {
        // reset planszy
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

        for (int i = 0; i < 9; i++) {
            wypiszPlansze(plansza);

            if (zwyciezca != ' '){break;} 

            cout << "Teraz gra: " << terazGra << endl;

            while (true) {
                cout << "Wprowadz w & k od 0 do 2: ";
                cin >> w >> k;

                if (!cin || w < 0 || w > 2 || k < 0 || k > 2) {
                    cout << "Niepoprawne dane!" << endl;
                }
                else if (plansza[w][k] != ' ') {
                    cout << "Pole zajete!" << endl;
                }
                else break;

                cin.clear();
                cin.ignore(10000, '\n');
            }

            plansza[w][k] = terazGra;
            terazGra = (terazGra == graczX) ? graczO : graczX;

            // wiersze
            for (int r = 0; r < 3; r++){
                if (plansza[r][0] != ' ' && plansza[r][0] == plansza[r][1] && plansza[r][1] == plansza[r][2])
                    zwyciezca = plansza[r][0];
            }

            // kolumny
            for (int c = 0; c < 3; c++){
                if (plansza[0][c] != ' ' && plansza[0][c] == plansza[1][c] && plansza[1][c] == plansza[2][c])
                    zwyciezca = plansza[0][c];
            }

            // przekatne
            if (plansza[0][0] != ' ' && plansza[0][0] == plansza[1][1] && plansza[1][1] == plansza[2][2]){
                zwyciezca = plansza[0][0];
            }
            if (plansza[0][2] != ' ' && plansza[0][2] == plansza[1][1] && plansza[1][1] == plansza[2][0]){
                zwyciezca = plansza[0][2];
            }
        }

        wypiszPlansze(plansza);

        if (zwyciezca != ' '){
            cout << "Gracz " << zwyciezca << " wygral!\n";
        }
        else {
            cout << "Remis!\n";
        }

        cout << "Gramy dalej [t/n]: ";
        cin >> wybor;

    } while (wybor == 't' || wybor == 'T');

    return 0;
}
