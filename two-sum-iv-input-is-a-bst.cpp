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
    unordered_set<int> mp;
    bool solve(TreeNode*root,int k)
    {
        if(root==NULL) return 0;
        if(mp.find(k-root->val)!=mp.end())return 1;
        mp.insert(root->val);
        return solve(root->left,k)||solve(root->right,k);    
    }
    bool findTarget(TreeNode* root, int k) {
        return solve(root,k);
        
    }
};