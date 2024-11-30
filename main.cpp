#include <iostream>
using namespace std;

#define SIZE 9

bool canPlace(int grid[SIZE][SIZE], int r, int c, int value) {
    for (int i = 0; i < SIZE; i++) {
        if (grid[r][i] == value || grid[i][c] == value) {
            return false;
        }
    }

    int boxRow = r - r % 3, boxCol = c - c % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + boxRow][j + boxCol] == value) {
                return false;
            }
        }
    }
    return true;
}

bool solve(int grid[SIZE][SIZE]) {
    int row, col;
    bool isFilled = true;

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                isFilled = false;
                break;
            }
        }
        if (!isFilled) break;
    }

    if (isFilled) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (canPlace(grid, row, col, num)) {
            grid[row][col] = num;

            if (solve(grid)) {
                return true;
            }

            grid[row][col] = 0;
        }
    }
    return false;
}

void displayGrid(int grid[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int puzzle[SIZE][SIZE];

    cout << "Enter the Sudoku puzzle row by row, with 0 for empty cells:\n";
    
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter row " << i + 1 << ":";
        for (int j = 0; j < SIZE; j++) {
            cin >> puzzle[i][j];
        }
    }

    if (solve(puzzle)) {
        cout << "\nSolved Sudoku:\n";
        displayGrid(puzzle);
    } else {
        cout << "No solution exists." << endl;
    }
    
    return 0;
}
