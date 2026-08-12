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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        bool rowadded = false;
        while(!q.empty()){
            int n = q.size();
            level++;
            while (n--) {
                TreeNode* node = q.front();
                q.pop();
                TreeNode* tempL = node->left;
                TreeNode* tempR = node->right;
                if (level == depth - 1) {
                    node->left = new TreeNode(val);
                    node->right = new TreeNode(val);
                    node->left->left = tempL;
                    node->right->right = tempR;
                    rowadded = true;
                }
                if (tempL)
                    q.push(tempL);
                if (tempR)
                    q.push(tempR);
            }
            if (rowadded)
                break;
        }
        return root;
    }
};