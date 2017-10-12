#include <iostream>
#include <cstdlib>
#include <time.h>

// Nolan Groves
// Lab 06 - You don't even get to play

using namespace std;

//NUMBER OF ROWS AND COLUMNS
const int ROWS = 15;
const int COLS = 15;
const int GENS = 10;

int neigbors(char arr[ROWS][COLS], int x, int y) {
    int num = 0;
    int self = 0;
    if (arr[x][y] == '*') {
        self = 1;
    }
    for (int i = max(0, x-1); i <= min(x+1, ROWS-1); i++) {
        for (int j = max(0, y-1); j <= min(y+1, COLS-1); j++) {
                if (arr[i][j] == '*') {
                    num++;
                }
        }
    }
    return (num - self);
}

void print_arr(char arr[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
    return;
}


int main()
{
    char life[ROWS][COLS];
    int counts[ROWS][COLS];

	//RANDOM NUMBER GENERATOR TO CREATE INITIAL GENERATION
	srand (time(NULL));
	int cell;

	for(int r=0; r<ROWS; r++)
	{
		for(int c =0; c<COLS;c++)
		{
			cell = rand() % 7;
			if(cell >= 5)
			{
				life[r][c] = '*';
			}
			else
			{
				life[r][c]=' ';
			}
		}
	}

	// Main Loop

	for (int g = 0; g<GENS; g++) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                counts[i][j] = neigbors(life, i, j);
            }
        }
        cout << "Generation: "<<g <<endl;
        print_arr(life);
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                char self = ' ';
                if (counts[i][j] < 2) {
                    self = ' ';
                } else if (counts[i][j] == 2) {
                    self = life[i][j];
                } else if (counts[i][j] == 3) {
                    self = '*';
                } else {
                    self = ' ';
                }

                life[i][j] = self;
            }
        }
	}


	return 0;

}
