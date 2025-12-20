#include <iostream>
using namespace std;

int max(int num1, int num2, int num3){
    if (num1 > num2 && num1 > num3) {
        return num1;
    }else if (num2 > num1 && num2 > num3){
        return num2;
    }else{
        return num3;
    }
    
}

int main() {
    int num1,num2,num3;
    char q;
    do
    {
        cout << "3 liczby calkowite: ";
        cin >> num1 >> num2 >> num3;
        cout << "Najwieksza liczba: " << max(num1, num2, num3) << endl; 
        cout << "Kontynuować ";
    } while (q != 'q' || q != 'Q');
}