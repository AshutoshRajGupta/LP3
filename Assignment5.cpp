#include <iostream>
#include <vector>
using namespace std;

// Function to check if a queen can be placed at the given row and column
bool isSafe(const vector<vector<int>>& board, int row, int col, int N) {
    // Check for queens in the same column
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Check for queens in the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check for queens in the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true; // No conflicts found, it's safe to place a queen
}

// Recursive function to solve the N-Queens problem
bool solveNQueens(vector<vector<int>>& board, int row, int N) {
    // Base case: If all queens are placed, return true
    if (row == N) {
        return true;
    }

    // Try placing a queen in each column of the current row
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col, N)) {
            // Place the queen
            board[row][col] = 1;

            // Recur for the next row
            if (solveNQueens(board, row + 1, N)) {
                return true;
            }

            // If placing the queen doesn't lead to a solution, backtrack and remove it
            board[row][col] = 0;
        }
    }

    return false; // No solution found for the current configuration
}

// Function to print the final N-Queens matrix
void printBoard(const vector<vector<int>>& board) {
    int N = board.size();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int N = 8; // Change N to the desired number of queens

    vector<vector<int>> board(N, vector<int>(N, 0));

    // Place the first queen at the top-left corner (0, 0)
    board[0][0] = 1;

    // Solve the N-Queens problem and print the final board
    if (solveNQueens(board, 1, N)) {
        cout << "Solution exists!" << endl;
        printBoard(board);
    } else {
        cout << "No solution exists for N = " << N << "." << endl;
    }

    return 0;
}
