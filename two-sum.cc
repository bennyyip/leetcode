// Brute force
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    size_t len = nums.size();
    for (size_t i = 0; i < len - 1; i++)
      for (size_t j = i + 1; j < len; j++)
        if (nums[i] + nums[j] == target)
          return vector<int>{i, j};
  }
};

// Sort
class Solution {
public:
  vector<int> twoSum(vector<int>& a, int s) {
    vector<int> r(a.size());
    iota(r.begin(), r.end(), 0);
    sort(r.begin(), r.end(), [&](int x, int y) { return a[x] < a[y]; });
    for (size_t i = 0, j = a.size() - 1; i < j; i++) {
      while (j > i + 1 && a[r[i]] + a[r[j]] > s)
        j--;
      if (a[r[i]] + a[r[j]] == s) {
        int x = r[i], y = r[j];
        r.clear();
        if (x > y)
          swap(x, y);
        r.push_back(x);
        r.push_back(y);
        break;
      }
    }
    return r;
  }
};
