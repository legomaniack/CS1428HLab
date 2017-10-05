#include <iostream>

// Nolan Groves
// Lab 05 - Why can't you just multiply them yourself

using namespace std;

int main () {
    float price;
    float tip;
    cout << "Enter price of meal: "; cin >> price;
    if ( price < 0 ) {
            cout << "Price cannot be negative";
            return -1;
    }
    cout << "Enter tip percentage: "; cin >> tip;
    if ( tip < 0 ) {
            cout << "Tip cannot be negative";
            return -1;
    }
    cout << "Tip: "<< (price * (tip*.01)) << endl;
    return 0;
}
