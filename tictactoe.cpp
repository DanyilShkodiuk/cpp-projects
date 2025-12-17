#include <iostream>
#include <string>
using namespace std;

void wypiszTabele(char tabela[3][3]) {
    for (int i = 0; i < 3; i++) {
        cout << "   |   |   " << endl;
        cout << " " << tabela[i][0] << " | " << tabela[i][1] << " | " << tabela[i][2] << endl;

        if (i < 2) {
            cout << "___|___|___" << endl;
        }
    }
    cout << "   |   |   " << endl;
}

main() {
    char tabela[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    const char graczX = 'X';
    const char graczO = 'O';
    char terazGra = graczX;
    int w,k = -1;
    char zwyciezca = ' ';

    for (int i = 0; i < 9; i++) {
        wypiszTabele(tabela);

        if(zwyciezca != ' ') {
            break;
        }

        cout << "Teraz gra: " << terazGra << endl;
        while(true) {
            cout << "Wprowadz w & k od 0 do 2 dla wiersza i kolumny: ";
            cin >> w >> k;
            if (w < 0 || w > 2 || k < 0 || k > 2) {
                cout << "Niepoprawna liczba, sprobuj ponownie." << endl;
            }else if (tabela[w][k] != ' ') {
                cout << "Pole wypelnione, sprobuj ponownie" << endl;
            }else {
                break;
            }
            w,k = -1;
            cin.clear();
            cin.ignore(10000, '\n');
        }

        tabela[w][k] = terazGra;
        terazGra = (terazGra == graczX) ? graczO : graczX;

        for (int w = 0; w < 3; w++) {
            if (tabela[w][0] != ' ' && tabela[w][0] == tabela[w][1] && tabela[w][1] == tabela[w][2]){
                zwyciezca = tabela[w][0];
                break;
            }
        }

        for (int k = 0; k < 3; k++) {
            if (tabela[0][k] != ' ' && tabela[0][k] == tabela[1][k] && tabela[1][k] == tabela[2][k]){
                zwyciezca = tabela[0][k];
                break;
            }
        }

        if(tabela[0][0] != ' ' && tabela[0][0] == tabela[1][1] && tabela[1][1] == tabela[2][2]) {
            zwyciezca = tabela[0][0];
        }
        else if (tabela[0][2] != ' ' && tabela[0][2] == tabela[1][1] && tabela[1][1] == tabela[2][0]){
            zwyciezca = tabela[0][2];
        }
    }
    if(zwyciezca != ' ') {
        cout << "Gracz " << zwyciezca << " wygral!" << endl;
    }else {
        cout << "Remis!" << endl;
    }
}
