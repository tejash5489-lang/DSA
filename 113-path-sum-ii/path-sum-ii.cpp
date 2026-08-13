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
    vector<vector<int>> ans;
    void solve(TreeNode* root, int k, vector<int> temp, int sum) {
        if (!root)
            return;
        sum += root->val;
        temp.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            if (sum == k) {
                ans.push_back(temp);
            }
            return;
        }

        solve(root->left, k, temp, sum);
        solve(root->right, k, temp, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int> temp;
        solve(root, targetSum, temp, sum);
        return ans;
    }
};