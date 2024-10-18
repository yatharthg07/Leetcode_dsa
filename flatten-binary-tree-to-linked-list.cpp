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

    TreeNode* solve(TreeNode* root)
    {
        if(root==NULL) return NULL;
        TreeNode* lt=solve(root->left);
        TreeNode* rt=solve(root->right);
        if(lt==NULL&&rt==NULL) return root;
        if(lt==NULL) return rt;
        if(rt==NULL)
        {
            root->right=root->left;
            root->left=NULL;
            return lt;
        }
        lt->right=root->right;
        root->right=root->left;
        root->left=NULL;
        return rt;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};