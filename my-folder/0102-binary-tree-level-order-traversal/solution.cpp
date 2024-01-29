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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL)
        {
            return res;
        }

        else if (root->left==NULL  && root->right==NULL)
        {
            res.push_back({root->val});
            return res;
        }
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> lvl;
            int size=q.size();
            for(int i=0;i<size;i++)
            {
            TreeNode *temp = q.front(); 
            q.pop(); 
            
            if(temp->left != NULL) 
                q.push(temp->left); 
            if(temp->right != NULL) 
                q.push(temp->right); 
                
            lvl.push_back(temp->val); 
            }
            res.push_back(lvl);

        }
        return res;
        
    }
};
