class Solution {

    bool nextPermutation(vector<int> &nums) {
        if (nums.size() <= 1)
            return false;
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
                return true;
            }
        }
        // just reverse if desc
        return false;
        /* reverse(nums.begin(), nums.end()); */
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> r;
        sort(nums.begin(), nums.end());
        do
            r.push_back(nums);
        while (nextPermutation(nums));
        return r;
    }
};
