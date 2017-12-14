class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        size_t i;
        for (i = 0; i < strs[0].size(); ++i) {
            char ch = strs[0][i];
            if (!all_of(strs.begin(), strs.end(),
                        [=](const string &str) { return str[i] == ch; }))
                break;
        }
        return strs[0].substr(0, i);
    }
};
