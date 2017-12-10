class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1)
            return s;
        string r;
        for (size_t i = 0; i < numRows; i++) {
            for (size_t j = i; j < s.size(); j += 2 * numRows - 2) {
                r += s[j];
                if (i > 0 && i < numRows - 1 &&
                    j + 2 * (numRows - i - 1) < s.size())
                    r += s[j + 2 * (numRows - i - 1)];
            }
        }
        return r;
    }
};
