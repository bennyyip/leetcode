class Solution {
public:
    void f(vector<vector<int>> &r, vector<int> &curr, vector<int> &candidates,
           int i, int target) {
        if (i == candidates.size()) {
            if (target == 0) {
                r.push_back(curr);
            }
        } else {
            f(r, curr, candidates, i + 1, target);
            int c = 0;
            while (target >= candidates[i]) {
                target -= candidates[i];
                curr.push_back(candidates[i]);
                f(r, curr, candidates, i + 1, target);
                c++;
            }
            curr.erase(curr.end() - c, curr.end());
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> r;
        vector<int> curr;
        candidates.erase(unique(candidates.begin(), candidates.end()),
                         candidates.end());
        sort(candidates.begin(), candidates.end());
        f(r, curr, candidates, 0, target);
	return r;
    }
};
