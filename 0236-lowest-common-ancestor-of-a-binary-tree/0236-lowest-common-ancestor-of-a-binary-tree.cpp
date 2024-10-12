/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root==NULL) return NULL;
        if(root==p||root==q) return root;
        auto lefttree=rec(root->left,p,q);
        auto righttree=rec(root->right,p,q);
        if(!lefttree) return righttree;
        else if(!righttree) return lefttree;
        else return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {  
        return rec(root,p,q);
    }
};