/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (!root)
            return 0;

        int hl = height(root->left);
        int hr = height(root->right);

        return max(hl, hr) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;

        int lh = height(root->left);
        int lr = height(root->right);

        if (abs(lh - lr) > 1)
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }
};