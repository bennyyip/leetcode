class Solution {
public:
    bool isValidSudoku(vector<vector<char>> &board) {
        int8_t r[9][9] = {}, c[9][9] = {}, b[9][9] = {};
        for (size_t i = 0; i < 9; i++)
            for (size_t j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int x = board[i][j] - '1';
                    if (r[i][x]++ || c[j][x]++ || b[i / 3 * 3 + j / 3][x]++)
                        return false;
                }
        return true;
    }
};
