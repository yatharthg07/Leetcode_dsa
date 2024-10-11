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
    int ans=0;
    void rec(TreeNode* root , int maxi)
    {
        if(root==NULL)  return ;
        if(root->val>=maxi)
        {
            ans++;
        }
        rec(root->left,max(root->val,maxi));
        rec(root->right,max(root->val,maxi));

    }
    int goodNodes(TreeNode* root) {
        rec(root,root->val);
        return ans;
    }
};