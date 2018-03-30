class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
	vector<int> r;
        unordered_map<int, int> f;
        int mf = 0;

        for (int x : nums)
            mf = max(mf, ++f[x]);

        vector<int> c(mf + 1, 0);
        for (auto &x : f)
            c[x.second]++;
        int l = 0;
        for (int i = mf; k > 0; i--) {
            k -= c[i];
            l = i;
        }
        for (auto &x : f)
            if (x.second > l || x.second == l && ++k > 0)
                r.push_back(x.first);
        return r;
    }
};
