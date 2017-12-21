class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size();
        if (n < 2)
            return n;
        int r = 1;
        for (size_t i = 1; i < n; i++)
            if (nums[i] != nums[i - 1])
                nums[r++] = nums[i];
        return r;
    }
};
