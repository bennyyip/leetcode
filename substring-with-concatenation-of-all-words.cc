class Solution {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        int m = words[0].size();
        int n = s.size();
        vector<int> r;

        unordered_map<string, int> count;

        if (m * words.size() > n)
            return r;

        for (auto x : words) {
            ++count[x];
        }

        for (int i = 0; i < n - m + 1; ++i) {
            bool f = true;
            unordered_map<string, int> seen;
            for (int j = i; j < i + m * words.size(); j += m) {
                string t = s.substr(j, m);
                if (!count.count(t) || ++seen[t] > count[t]) {
                    f = false;
                    break;
                }
            }
            if (f)
                r.push_back(i);
        }
        return r;
    }
};
