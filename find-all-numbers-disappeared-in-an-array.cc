class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        for (int x : nums) {
            int idx = abs(x) - 1;
            nums[idx] = -abs(nums[idx]);
        }
        vector<int> r;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] < 0)
                r.push_back(i + 1);
        }
        return r;
    }
};
