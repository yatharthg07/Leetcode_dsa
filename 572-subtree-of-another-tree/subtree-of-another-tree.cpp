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
    bool check(TreeNode* root, TreeNode* subRoot)
    {
        if(!root||!subRoot)
        {
            return root==subRoot;
        }
        return (root->val==subRoot->val)&& check(root->left,subRoot->left) && check(root->right,subRoot->right);
    }
    bool ans=0;
    void rec(TreeNode* root,TreeNode* subRoot)
    {
        if(!root) return;
        if(check(root,subRoot)){
            ans=1;
            return;
        }
        rec(root->left,subRoot);
        rec(root->right,subRoot);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        rec(root,subRoot);
        return ans;
    }
};