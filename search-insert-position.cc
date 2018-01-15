class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return r == nums.size() ? r : nums[r - 1] == target ? r - 1 : r;
    }
};

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};

class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo >> 1);
            if (nums[mid] < target)
                lo = mid + 1;
            else
                hi = mid;
        }
        return lo;
    }
};
