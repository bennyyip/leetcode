// N[i] = min { N[i - j * j] + 1}, where j * j <=i
// N[0] = 1

class Solution {
public:
    int numSquares(int n) {
        if (n <= 0)
            return 0;
        vector<int> N(n + 1, INT_MAX);
        N[0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j * j <= i; ++j) {
                N[i] = min(N[i - j * j] + 1, N[i]);
            }
        }
        return N[n];
    }
};
