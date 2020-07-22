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
    void dfs(TreeNode* root, int idx, vector<vector<int>>& res)
    {
        if(idx==res.size())
            res.push_back({root->val});
        else
            res[idx].push_back(root->val);
        
        if(root->left)
            dfs(root->left, idx+1, res);
        
        if(root->right)
            dfs(root->right, idx+1, res);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        
        vector<vector<int>> res;
        
        dfs(root,0,res);
        
        for(int i=0; i<res.size(); i++)
            if(i%2 != 0)
                reverse(res[i].begin(), res[i].end());
        
        return res;
    }
};
