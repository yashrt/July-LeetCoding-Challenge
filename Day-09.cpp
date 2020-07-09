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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        
        int res = 1;
        queue<pair<TreeNode*, int> > Q;
        Q.push({root,0});
        
        while(!Q.empty())
        {
            int count = Q.size();
            int first  = Q.front().second;
            int last = Q.back().second;
            res  = max(res, last-first+1);
            
            while(count--)
            {
                pair<TreeNode*, int> temp = Q.front();
                int parentID = temp.second - first;
                Q.pop();
                
                if(temp.first->left)
                    Q.push({temp.first->left, 2*parentID+1});
                
                if(temp.first->right)
                    Q.push({temp.first->right, 2*parentID+2});
            }
        }
        return res;
    }
};
