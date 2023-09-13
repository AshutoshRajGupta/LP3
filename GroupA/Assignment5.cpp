#include <iostream>
#include <vector>
using namespace std;

void printQueens(const vector<int>& board) {
    int n = board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i] == j) cout << "Q ";
            else cout << "* ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at the given position
bool isSafe(const vector<int>& board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < row; i++) {
        if (board[i] == col || 
            abs(board[i] - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

// Backtracking function to find N-Queens solution
bool solveNQueens(vector<int>& board, int row) {
    int n = board.size();
    // If all queens are placed, return true
    if (row == n) {
        printQueens(board);
        return true;
    }
    bool found = false;
    // Try placing a queen in each column of the current row
    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            found |= solveNQueens(board, row + 1);
            board[row] = -1; // Backtrack
        }
    }
    return found;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Invalid input. Please enter a positive integer." << endl;
        return 1;
    }

    vector<int> board(n, -1); // Initialize the board with -1 (no queens placed yet)
    
    int firstQueenColumn;
    cout << "Enter the column (0-indexed) for the first queen: ";
    cin >> firstQueenColumn;

    if (firstQueenColumn < 0 || firstQueenColumn >= n) {
        cout << "Invalid input for the first queen's column." << endl;
        return 1;
    }

    board[0] = firstQueenColumn; // Place the first queen

    if (!solveNQueens(board, 1)) {
        cout << "No solution found." << endl;
    }

    return 0;
}
