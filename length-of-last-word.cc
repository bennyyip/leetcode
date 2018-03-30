class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = 0;
        int n = s.size();
        while (n > 0 && isspace(s[n - 1]))
            n--;
        for (int i = 0; i < n; ++i) {
            if (isspace(s[i]))
                r = 0;
            else
                r++;
        }
        return r;
    }
};
