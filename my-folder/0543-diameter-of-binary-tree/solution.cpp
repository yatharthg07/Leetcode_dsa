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


    int dia=INT_MIN;
    int depth(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=depth(root->left);
        int rh=depth(root->right);
        dia=max(lh+rh,dia);

        return 1+max(lh,rh);
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int dummy= depth(root);
        return dia;
        
    }
};
