/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>> q;
        vector<vector<int>> ans;

        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* node=p.first;
            int hd=p.second.first,lvl=p.second.second;
            nodes[hd][lvl].insert(node->val);
            if(node->left){
                q.push({node->left,{hd-1,lvl+1}});
            }

            if(node->right){
                q.push({node->right,{hd+1,lvl+1}});
            }
        }

            // vector<vector<int>> ans;
            for(auto a:nodes){
                vector<int> col;
                for(auto q:a.second){
                    col.insert(col.end(),q.second.begin(),q.second.end());
                }
                ans.push_back(col);
            }

        return ans;
    }
};