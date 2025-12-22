#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main() {
    int x = time(0);
    int N = 4;
    int matrix[N][N];
    
    srand(x);

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++) {
            matrix[i][j] = 1 + rand() % 9;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";       
        }
        cout << endl;
    }

    int sumMain = 0;
    int sumSecondary = 0;
    for (int i = 0; i < N; i++) {
        sumMain += matrix[i][i];
        sumSecondary += matrix[i][N - 1 - i];
    }

    cout << "Suma przekatnej glownej: " << sumMain << endl;
    cout << "Suma przekatnej bocznej: " << sumSecondary << endl;
    return 0;
}