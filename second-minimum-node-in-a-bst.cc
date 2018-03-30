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
    int findSecondMinimumValue(TreeNode *root) {
        if (!root)
            return -1;
        vector<TreeNode *> s;
        s.push_back(root);
        while (root->left) {
            s.push_back(root->left);
            root = root->left;
        }

        int smallest = root->val;

        while (!s.empty()) {
            TreeNode *x = s.back();
            s.pop_back();
            while (x) {
                if (smallest < x->val)
                    return x->val;
                x = x->right;
            }
        }
        return -1;
    }
};
