class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int i = 0;
        for (int x : nums) {
            if (x)
                nums[i++] = x;
        }
        while (i < nums.size())
            nums[i++] = 0;
    }
};
