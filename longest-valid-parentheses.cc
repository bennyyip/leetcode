class Solution {
public:
    int longestValidParentheses(string s) {
        stack<char *> stk;
        int r = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')' && !stk.empty() && *stk.top() == '(') {
                stk.pop();
                r = max(r, stk.empty()
                               ? i + 1
                               : i - static_cast<int>(stk.top() - s.c_str()));
            } else {
                stk.push(&s[i]);
            }
        }
        return r;
    }
};
