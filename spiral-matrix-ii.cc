class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> r(n, vector<int>(n));

        int x = 1;

        for (int i = 0; i < (n + 1) / 2; ++i) {
            for (int j = i; j < n - i; ++j)
                r[i][j] = x++;
            for (int j = i + 1; j < n - i; ++j)
                r[j][n - i - 1] = x++;
            if (i < n / 2) {
                for (int j = n - i - 2; j >= i; --j)
                    r[n - i - 1][j] = x++;
                for (int j = n - 2 - i; j > i; --j)
                    r[j][i] = x++;
            }
        }

        return r;
    }
};
