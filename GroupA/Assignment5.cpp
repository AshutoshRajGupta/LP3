#include <iostream>
#include <vector>

bool isSafe(const std::vector<int>& board, int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i] == col || board[i] == col - (row - i) || board[i] == col + (row - i)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(std::vector<int>& board, int row, int n, int& count) {
    if (row == n) {
        count++;
        return;
    }

    for (int col = 0; col < n; col++) {
        if (col == board[0]) {
            continue;  // Skip the column of the first queen
        }

        if (isSafe(board, row, col)) {
            board[row] = col;
            solveNQueens(board, row + 1, n, count);
        }
    }
}

int main() {
    int n;
    std::cout << "Enter the number of queens (N): ";
    std::cin >> n;

    std::vector<int> board(n, -1);
    std::cout << "Enter the column position of the first queen (0-based indexing): ";
    std::cin >> board[0];

    int count = 0;
    solveNQueens(board, 1, n, count);

    std::cout << "Total solutions: " << count << std::endl;

    return 0;
}
