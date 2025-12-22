#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
    int x = time(0);
    srand(x);
    //1.stworz plansze
    int matrix[5][5];
    //2.wylosuj pozycje skarbu
    int rowS = rand() % 5;
    int colS = rand() % 5;
    cout << rowS << " " << colS << endl;

    //3.User podaje wspolrzedne
    cout << "Podaj wspolrzedne (0-5): ";
    int row = 0;
    int col = 0;
    
    //4.informacja czy trafil czy nie
    bool trafil = false;
    
    while(!trafil){
        cout << "jakie: ";
        cin >> row >> col;
        if(row == rowS && col == colS) {
            cout << "trafiles!" << endl;
            trafil = true; 
        } else {
            cout << "nie trafiles" << endl;
        }
    }
}