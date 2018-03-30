/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// pick a node(i) as root,
// left tree can be: tree(0, i-1)
// right tree can be: tree(i+1, n-1)

// fill the table bottom up

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<vector<vector<TreeNode *>>> a(n, vector<vector<TreeNode *>>(n));
        vector<TreeNode *> dummy(1, nullptr);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                for (int k = i; k <= j; ++k) {
                    for (auto lt : i < k ? a[i][k - 1] : dummy) {
                        for (auto rt : k < j ? a[k + 1][j] : dummy) {
                            TreeNode *root = new TreeNode(k + 1);
                            root->left = lt;
                            root->right = rt;
                            a[i][j].push_back(root);
                        }
                    }
                }
            }
        }
        vector<TreeNode *> nil;
        return n > 0 ? a[0][n - 1] : nil;
    }
};
