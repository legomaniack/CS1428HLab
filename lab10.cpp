#include <iostream>
#include <cmath>


// Nolan Groves
// Lab 10 - Happius Primicus

using namespace std;

const int SIZE = 20;
int counti = 0;

bool isPrime(int n) {
    for (int i = 2; i < n; i++) {
        if (n%i == 0) {
                return false;
        }
    }
    return true;
}

void selectionSort(int cycle[]) {
    int mi;
    int temp;
    for (int i=0; i<counti; i++) {
        mi = i;
        for (int j = i; j<counti; j++) {
            if (cycle[j] < cycle[mi]) {
                mi = j;
            }
        }
        temp = cycle[i];
        cycle[i] = cycle[mi];
        cycle[mi] = temp;
    }
}

bool cycleContains(int cycle[], int n){
    for(int i = 0; i<counti; i++){
        if(cycle[i] > n) {
                return false;
        }
        if(cycle[i] == n) {
                return true;
        }
    }

    return false;
}

bool addToCycle(int cycle[], int n){
    if(cycleContains(cycle, n)) {
            return false;
    }
    if (counti>= SIZE) {
        return false;
    }
    cycle[counti++] = n;
    selectionSort(cycle);
    return true;
}

bool isHappy(int n) {
    int cycle[SIZE];
    counti = 0;
    int total = 0;
    int nums = n;
    while(true) {
        total = 0;
        while(nums > 0) {
            total += pow((nums % 10),2);

            nums /= 10;
        }
        if (total == 1) return true;
        if (addToCycle(cycle, total) == false) {
                return false;
        }
        nums = total;
    }
}

int main() {
    int n;
    cout << "Enter number: ";cin >> n;
    if (isPrime(n) && isHappy(n)) {
        cout<<"Happy Prime!"<<endl;
    } else {
        cout<<"No"<<endl;
    }
    return 0;
}
