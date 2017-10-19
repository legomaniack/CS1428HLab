#include <iostream>
#include <cmath>
#include <fstream>

// Nolan Groves
// Lab 07 - Reverse assembly 2: This time it's personal

using namespace std;

int main() {
    const int OP_ADD = 0;
    const int OP_SUB = 1;
    const int OP_MUL = 2;
    const int OP_DIV = 3;
    const int OP_MOD = 4;
    const int OP_EXP = 5;
    const int OP_RED = 6;
    const int OP_WRT = 7;
    const int OP_STR = 8;

    int mem[256];

    fstream fin;
    fin.open("code.txt");
    int data[4];
    do {
        for (int i=0; i<4; i++) {
            fin >> data[i];
        }
        if (data[1] > 255 || data[2] > 255 || data[3] > 255 || data[1] < 0 || data[2] < 0 || data[3] < 0 ) {
            cout << "Invalid address";
        }
        switch (data[0]) {
            case OP_ADD:
                mem[data[1]] = mem[data[2]] + mem[data[3]];
                break;
            case OP_SUB:
                mem[data[1]] = mem[data[2]] - mem[data[3]];
                break;
            case OP_MUL:
                mem[data[1]] = mem[data[2]] * mem[data[3]];
                break;
            case OP_DIV:
                mem[data[1]] = mem[data[2]] / mem[data[3]];
                break;
            case OP_MOD:
                mem[data[1]] = mem[data[2]] % mem[data[3]];
                break;
            case OP_EXP:
                mem[data[1]] = pow(mem[data[2]], mem[data[3]]);
                break;
            case OP_RED:
                cout << "Input: ";
                cin >> mem[data[1]];
                break;
            case OP_WRT:
                cout << "Output: " << mem[data[1]] << endl;
                break;
            case OP_STR:
                mem[data[1]] = data[2];
                break;
            default:
                cout << "Invalid command code";
                return -1;
        }
    } while (!fin.eof());
    /*
    cout << "Memory dump: "<< endl;
    for (int i = 0; i < 10; i++) {
        cout << mem[i] << endl;
    } */
    return 0;
}
