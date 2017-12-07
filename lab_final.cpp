#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

// Nolan Groves
// Final Lab - As the scrolls have foretold

using namespace std;

 void betFunc(int myMoney, int& bet) {
    cout << "You currently have $" << myMoney << endl;
    while(true){
        cout << "How much do you bet?" << endl;
        int temp;
        cout << "$ ";cin >> temp;
        if (temp <= myMoney) {
            bet = temp;
            return;
        }
        cout << "You do not have that much" << endl;
    }
 }

 void getRolls(int& compDie1, int& userDie1) {
    srand(time(NULL));
    compDie1 = rand()%6 + 1;
    userDie1 = rand()%6 + 1;
    cout << "You rolled a " << userDie1 << endl;
    cout << "Your opponent rolled a " << compDie1 << endl;
 }

 void results(int compDie1, int userDie1, int& myMoney, int betAmount) {
    if (userDie1 > compDie1) {
        cout << "You gain $" << betAmount << endl;
        myMoney += betAmount;
    } else if (userDie1 < compDie1) {
        cout << "You lose $" << betAmount << endl;
        myMoney -= betAmount;
    } else if (userDie1 == compDie1) {
        cout << "You tied" << endl;
    }
 }

 int main() {
    int myMoney = 1000;
    int bet;
    int compDie1;
    int userDie1;
    char ans;
    while(true) {
        betFunc(myMoney, bet);
        getRolls(compDie1, userDie1);
        results(compDie1,userDie1,myMoney,bet);
        cout << endl;
        if (myMoney <= 0) {
            cout << "You ran out of money :(" << endl;
            break;
        }

        cout << "Would you like to continue? [Y/n]";cin >> ans;
        if (ans == 'n' || ans == 'N') break;
    }
    cout << "You ended with $" << myMoney <<endl;
    return 0;
 }

