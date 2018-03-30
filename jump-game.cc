class Solution {
public:
    bool canJump(vector<int> &nums) {
        int reach = 0, n = nums.size();
        for (int i = 0; i < n && reach >= i; ++i) {
            reach = max(reach, i + nums[i]);
        }
        return reach >= (n - 1);
    }
};

// TLE
/* class Solution { */
/* public: */
/*     bool canJump(vector<int> &nums) { */
/*         int n = nums.size(); */
/*         vector<bool> can_jump(n, false); */
/*         can_jump[0] = true; */
/*         for (int i = 0; i < n; ++i) */
/*             if (can_jump[i]) */
/*                 for (int j = i + 1; j <= nums[i] + i; ++j) */
/*                     if (j >= n) */
/*                         break; */
/*                     else */
/*                         can_jump[j] = true; */
/*         return can_jump.back(); */
/*     } */
/* }; */
