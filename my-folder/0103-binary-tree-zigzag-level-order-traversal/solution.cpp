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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
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
        bool flag=0;
        while(!q.empty())
        {
            
            int size=q.size();
            vector<int> lvl(size);
            for(int i=0;i<size;i++)
            {
            TreeNode *temp = q.front(); 
            q.pop(); 
            
            if(temp->left != NULL) 
                q.push(temp->left); 
            if(temp->right != NULL) 
                q.push(temp->right); 
            if(flag==0)    
            lvl[i]=temp->val; 
            else
            lvl[size-i-1]=temp->val;
            }
            res.push_back(lvl);
            flag=!flag;
        }
        return res;
        
    }
};
