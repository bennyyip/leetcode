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
    int kthSmallest(TreeNode *root, int &k) {
        if (root) {
            int x = kthSmallest(root->left, k);
            if (k == 0) {
                return x;
            } else if (--k == 0) {
                return root->val;
            } else {
                return kthSmallest(root->right, k);
            }
        } else {
            return NULL;
        }
    }
};
