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
    TreeNode* reverseOddLevels(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        int level = 0;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<TreeNode*> levelnodes;
            while (size--) {
                TreeNode* node = q.front();
                q.pop();
                levelnodes.push_back(node);

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            if (level % 2 == 1) {
                int i = 0;
                int j = levelnodes.size() - 1;
                while (i < j) {
                    int tempval = levelnodes[i]->val;
                    levelnodes[i]->val = levelnodes[j]->val;
                    levelnodes[j]->val = tempval;
                    i++;
                    j--;
                }
            }
            level++;
        }
        return root;
    }
};