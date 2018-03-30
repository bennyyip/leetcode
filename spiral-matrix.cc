class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &a) {
        vector<int> r;
        if (a.empty() || a[0].empty())
            return r;
        int m = a.size(), n = a[0].size();

        for (int i = 0; i < (min(n, m) + 1) / 2; ++i) {
            for (int j = i; j < n - i; ++j)
                r.push_back(a[i][j]);
            for (int j = i + 1; j < m - i; ++j)
                r.push_back(a[j][n - i - 1]);
            if (i < m / 2)
                for (int j = n - i - 2; j >= i; --j)
                    r.push_back(a[m - i - 1][j]);
            if (i < n / 2)
                for (int j = m - 2 - i; j > i; --j)
                    r.push_back(a[j][i]);
        }
        return r;
    }
};
