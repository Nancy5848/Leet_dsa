class Solution {
public:
    vector<vector<string>> result;
    vector<string> board;
    vector<bool> col, diag1, diag2;

    void backtrack(int row, int n) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            // Check column and diagonals
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            // Place queen
            board[row][c] = 'Q';
            col[c] = true;
            diag1[row - c + n - 1] = true;
            diag2[row + c] = true;

            // Move to next row
            backtrack(row + 1, n);

            // Remove queen (backtrack)
            board[row][c] = '.';
            col[c] = false;
            diag1[row - c + n - 1] = false;
            diag2[row + c] = false;
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));

        col = vector<bool>(n, false);
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);

        backtrack(0, n);

        return result;
    }
};