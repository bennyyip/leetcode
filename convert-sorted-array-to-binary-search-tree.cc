/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *f(vector<int> &nums, int l, int r) {
        if (l == r)
            return NULL;
        int m = l + r >> 1;
        TreeNode *root = new TreeNode(nums[m]);
        root->left = f(nums, l, m);
        root->right = f(nums, m + 1, r);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return f(nums, 0, nums.size());
    }
};
