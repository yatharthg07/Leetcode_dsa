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
    vector<vector<int>> ans;
    vector<vector<int>> levelOrder(TreeNode* root) {
                if (root == nullptr) {
            return ans;  // Return an empty vector if the tree is empty
        }
        queue <TreeNode*> q;
        q.push(root);
        TreeNode* temp=root;
        while(q.size())
        {
            vector<int> level;

            int lvl=q.size();
            for(int i=0;i<lvl;i++)
            {
                temp=q.front();
                q.pop();
                level.push_back(temp->val);
                if(temp->left)
                {
                q.push(temp->left);
                }
                if(temp->right)
                {
                q.push(temp->right);
                }

            }
            ans.push_back(level);



            
        }
        return ans;
        
    }
};
