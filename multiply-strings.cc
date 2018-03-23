class Solution {
public:
    string multiply(string a, string b) {
        vector<int> r(a.size() + b.size(), 0);
        int m = a.size(), n = b.size();
        for (int i = 0; i < m; ++i) {
            int c = 0;
            for (int j = 0; j < n; ++j) {
                r[i + j] += (a[m - i - 1] - '0') * (b[n - j - 1] - '0') + c;
                c = r[i + j] / 10;
                r[i + j] %= 10;
            }
            if (c) {
                r[i + n] += c;
            }
        }
        while (r.size() > 1 && !r.back())
            r.pop_back();

        string rr;
        for (auto it = r.rbegin(); it != r.rend(); ++it)
            rr += '0' + *it;

        return rr;
    }
};
