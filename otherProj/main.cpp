#include <iostream>

using namespace std;

double cenaVat(double netto, double vat) {
    return netto * (1 + vat/100);
}

int main() {
    double netto, vat;
    while (netto > 0) {
        cout << "Podaj cene netto i VAT:" << endl;
        cout << "Netto: ";
        cin >> netto;
        cout << "VAT: ";
        cin >> vat;
        cout << "Cena brutto jest: " << cenaVat(netto, vat) << endl << endl; 
    }
}