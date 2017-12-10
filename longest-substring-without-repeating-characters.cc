class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0, m = -1;
        vector<int> c(127, -1);
        for (int i = 0; i < s.size(); ++i) {
            m = max(m, c[s[i]]);
            r = max(r, i - m);
            c[s[i]] = i;
        }
        return r;
    }
};
