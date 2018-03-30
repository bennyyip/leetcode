class Solution {
private:
    vector<int> a;

public:
    Solution(vector<int> nums) : a(nums) {}

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() { return a; }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        auto r = a;
        for (int i = 1; i < r.size(); ++i)
            swap(r[i], r[rand() % (i + 1)]);
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
