class Solution {
    vector<vector<int>> r;
    void f(vector<int> &nums, int i) {
        if (i == nums.size()) {
            r.push_back(nums);
        } else {
            for (int j = i; j < nums.size(); ++j) {
                swap(nums[i], nums[j]);
                f(nums, i + 1);
                swap(nums[i], nums[j]);
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums) {
        r.clear();
        f(nums, 0);
        return r;
    }
};
