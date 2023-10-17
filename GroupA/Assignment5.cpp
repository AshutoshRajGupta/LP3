#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || board[i] - i == col - row || board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void solveNQueens(vector<int>& board, int row, int n, int& count) {
    if (row == n) {
        count++;
        cout << "Solution " << count << ":\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << (board[i] == j ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, row + 1, n, count);
        }
    }
}

void solveNQueens(int n) {
    vector<int> board(n, -1);
    int count = 0;
    solveNQueens(board, 0, n, count);

    if (count == 0) {
        cout << "No solutions found.\n";
    } else {
        cout << "Total solutions: " << count << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    solveNQueens(n);

    return 0;
}
