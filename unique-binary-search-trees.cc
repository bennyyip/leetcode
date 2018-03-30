// f(n) = 1 if n <= 1
// f(n) = \sigma { f(a) * f(b) } where a + b + 1 == n

class Solution {
public:
    int numTrees(int n) {
        if (n < 1)
            return 0;

        vector<int> f(n + 1, 0);
        f[0] = f[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= i - 1; ++j) {
                f[i] += f[j] * f[i - j - 1];
            }
        }
        return f[n];
    }
};

// naive recursive
// f(a, b) = \sigma {f(a, i - 1) * f(i,i) * f(i + 1, b)}
// f(a, b) =1 if a >= b

class Solution {
    int f(int a, int b) {
        if (a >= b)
            return 1;
        int r = 0;
        for (int i = a; i <= b; ++i) {
            r += f(a, i - 1) * f(i, i) * f(i + 1, b);
        }
        return r;
    }

public:
    int numTrees(int n) { return f(1, n); }
};
