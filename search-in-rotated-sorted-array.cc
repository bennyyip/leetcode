class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();
        int lo = 0;
        int hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }

        int pivot = lo;
        lo = 0;
        hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int realmid = (mid + pivot) % n;
            if (nums[realmid] == target)
                return realmid;
            else if (nums[realmid] < target)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        return -1;
    }
};
