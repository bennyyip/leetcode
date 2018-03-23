class Solution {
public:
    void f(vector<vector<int>> &r, vector<int> &curr, vector<int> &a, int i,
           int s) {
        if (i == a.size()) {
            if (s == 0)
                r.push_back(curr);
        } else {
            if (s >= a[i]) {
                curr.push_back(a[i]);
                f(r, curr, a, i + 1, s - a[i]);
                curr.pop_back();
            }
            f(r, curr, a,
              find_if(a.begin() + i, a.end(),
                      bind(not_equal_to<int>(), placeholders::_1, a[i])) -
                  a.begin(),
              s);
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &a, int s) {
        vector<vector<int>> r;
        vector<int> curr;
        sort(a.begin(), a.end());
        f(r, curr, a, 0, s);
        return r;
    }
};
