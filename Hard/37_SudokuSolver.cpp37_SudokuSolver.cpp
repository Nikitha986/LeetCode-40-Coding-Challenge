class Solution {
public:
    bool solveSudokuHelper(vector<vector<char>>& board, int row, int col) {
        if (row == 9)
            return true;

        if (col == 9)
            return solveSudokuHelper(board, row + 1, 0);

        if (board[row][col] != '.')
            return solveSudokuHelper(board, row, col + 1);

        for (char num = '1'; num <= '9'; num++) {
            if (isValid(board, row, col, num)) {
                board[row][col] = num;

                if (solveSudokuHelper(board, row, col + 1))
                    return true;

                board[row][col] = '.';
            }
        }

        return false;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == num ||
                board[i][col] == num ||
                board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == num)
                return false;
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveSudokuHelper(board, 0, 0);
    }
};
