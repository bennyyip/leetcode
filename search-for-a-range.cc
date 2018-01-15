class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int lo = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (lo == nums.size() || nums[lo] != target)
            return vector<int>{-1, -1};

        int hi =
            upper_bound(nums.begin() + lo, nums.end(), target) - nums.begin();

        return vector<int>{lo, hi - 1};
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int> &a, int target) {
        int l = 0, m = a.size(), h = a.size();
        while (l < m) {
            int x = l + m >> 1;
            if (a[x] < target)
                l = x + 1;
            else
                m = x;
        }
        vector<int> r;
        if (l == a.size() || a[l] != target) {
            r.push_back(-1);
            r.push_back(-1);
        } else {
            while (m < h) {
                int x = m + h >> 1;
                if (a[x] <= target)
                    m = x + 1;
                else
                    h = x;
            }
            r.push_back(l);
            r.push_back(m - 1);
        }
        return r;
    }
};
