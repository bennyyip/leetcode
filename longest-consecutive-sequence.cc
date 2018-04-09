// Longest Consecutive Sequence
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int r = 0;
        unordered_set<int> s(nums.begin(), nums.end());
        for (auto i : num) {
            int j = i, k = i + 1;
            while (s.count(j - 1))
                s.erase(j--);
            while (s.count(k))
                s.erase(k++);
            r = max(r, k - j);
        }
        return r;
    }
};
