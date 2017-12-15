class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        size_t n = nums.size();
        int ret;
        int delta = INT_MAX;
        sort(nums.begin(), nums.end());
        for (size_t i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            size_t l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                int d = sum - target;
                if (abs(d) < delta) {
                    ret = sum;
                    delta = abs(d);
                }
                if (d < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        }
        return ret;
    }
};
