#include <iostream>
#include <cmath>


// Nolan Groves
// Lab 11 - Recursion

using namespace std;

const int SIZE = 20;
int counti = 0;

int factorial(int n) {
    if (n == 1) return n;
    return n*factorial(n-1);
}

int fib(int n) {
    if (n == 1 || n == 0) return n;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n;
    cout << "Enter number: ";cin >> n;
    cout << "Factorial: " << factorial(n)<< endl;
    cout << "Fibo: "<< fib(n) << endl;
    return 0;
}
