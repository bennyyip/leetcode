// TODO: Manacher's Algorithm, O(n) algorithm to find longest palindrome

class Solution {
public:
    /* O(n^2) */
    string longestPalindrome(string s) {
        int l = 0, r = 0;
        for (size_t i = 0; i < s.size(); i++) {
            int len1 = expandFromCenter(s, i, i);
            int len2 = expandFromCenter(s, i, i + 1);
            int len = max(len1, len2);
            /* abba  i = 1, len = 4 */
            /* ababa i = 2, len = 5 */
            if (len > r - l + 1) {
                l = i - (len - 1) / 2;
                r = i + len / 2;
            }
        }
        return s.substr(l, r - l + 1);
    }

    int expandFromCenter(const string &s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        return r - l - 1;
    }
};
