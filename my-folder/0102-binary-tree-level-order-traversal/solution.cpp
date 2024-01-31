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

// vector<vector<int>> ret;

// void buildVector(TreeNode *root, int depth)
// {
//     if(root == NULL) return;
//     if(ret.size() == depth)
//         ret.push_back(vector<int>());
    
//     ret[depth].push_back(root->val);
//     buildVector(root->left, depth + 1);
//     buildVector(root->right, depth + 1);
// }

// vector<vector<int> > levelOrder(TreeNode *root) {
//     buildVector(root, 0);
//     return ret;
// } 
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
