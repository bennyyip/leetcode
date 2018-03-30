class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> r(1 << (nums.size()));
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < r.size(); ++j) {
                if ((j + 1) & (1 << i)) {
                    r[j].push_back(nums[i]);
                }
            }
        }
        return r;
    }
};
