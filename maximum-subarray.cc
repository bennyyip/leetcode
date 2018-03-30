class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int r = nums[0], s = 0;
        for (int x : nums) {
            s = max(s, 0) + x;
            r = max(s, r);
        }
        return r;
    }
};
