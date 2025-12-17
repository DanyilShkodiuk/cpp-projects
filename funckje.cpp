#include <iostream>
#include <string>
using namespace std;

void przezWartosc(int x) {x += 10;}
void przezReferencje(int &x) {x += 10;}
void przezWskaznik(int *x) {*x += 10;}

int main(){
    int a = 5;
    przezWartosc(a);
    cout << "wartosc " << a << endl;
    przezReferencje(a);
    cout << "referencje " << a << endl;
    przezWskaznik(&a);
    cout << "wskaznik " << a << endl;

}