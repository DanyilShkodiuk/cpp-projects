#include <iostream>
#include <string>
using namespace std;


string helloWorld(string tekst) {
    for (int i = 0; i < 10; i ++) {
        cout << tekst << endl;
    }
    return tekst;
}

int main(){
    string tekst;
    cout << "wprowadz tekst: ";
    cin >> tekst;
    helloWorld(tekst);
}