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
    int maxsum;
    int solve(TreeNode* root) {
        if (root == NULL)
            return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int neeche_ans = l + r + root->val;

        int only_one = max(l, r) + root->val;

        int header = root->val;

        maxsum = max({maxsum, neeche_ans, only_one, header});

        return max(only_one, header);
    }
    int maxPathSum(TreeNode* root) {
        maxsum = INT_MIN;
        solve(root);
        return maxsum;
    }
};