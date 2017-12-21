// recurssive
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return {""};
        vector<string> r;
        for (size_t i = 0; i < n; i++) {
            for (auto x : generateParenthesis(i)) {
                for (auto y : generateParenthesis(n - i - 1)) {
                    r.push_back("(" + x + ")" + y);
                }
            }
        }
        return r;
    }
};

// iterative
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> r;
        r.resize(n + 1);
        r[0] = {""};
        for (size_t j = 1; j <= n; j++) {
            for (size_t i = 0; i < j; i++) {
                for (const auto &x : r[i]) {
                    for (const auto &y : r[j - i - 1]) {
                        r[j].push_back("(" + x + ")" + y);
                    }
                }
            }
        }
        return r[n];
    }
};

/* TODO: */
// Generate Parentheses
// Matters Computational: Ideas, Algorithms, Source Code 15.3
// prefix shifts

#define REP(i, n) for (int i = 0; i < (n); i++)

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> r;
        string s(2 * n, ')');
        int x = n - 1, y = n - 1, nq = 2 * n - 2;
        auto f = [&] { r.push_back(s); };
        REP(i, n)
            s[i] = '(';
        f();
        while (x < nq) {
            s[x++] = ')';
            s[y++] = '(';
            if (s[x] == ')') {
                if (x == 2 * y - 1)
                    x++;
                else {
                    s[x] = '(';
                    s[1] = ')';
                    x = 2;
                    y = 1;
                }
            }
            f();
        }
        return r;
    }
};
