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
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        bool check1=root->left?root->left->val<root->val:true;
        bool check2=root->right?root->right->val>root->val:true;
        return check1 && check2 && isValidBST(root->left) && isValidBST(root->right);
        
    }
};