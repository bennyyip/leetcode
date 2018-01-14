class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() <= 1)
            return;
        for (int i = nums.size() - 1; --i >= 0;) {
            // nums[i+1:] desc
            if (nums[i] < nums[i + 1]) {
                int j = nums.size();
                // find j >= i + 1, and
                // nums[j] > nums[i]
                while (!(nums[i] < nums[--j]))
                    ;
                // then swap i j
                swap(nums[i], nums[j]);
                // make it incr
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        // just reverse if desc
        reverse(nums.begin(), nums.end());
    }
};
