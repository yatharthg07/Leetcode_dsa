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
    long long cur=LLONG_MIN;
    bool preorder(TreeNode* root)
    {
        if(!root)
        {
            return true;
        }
        bool left= preorder(root->left);
        if(root->val<=cur)
        {
            return false;
        }
        cur=root->val;
        bool right= preorder(root->right);
        return left&&right;

    }
    bool isValidBST(TreeNode* root) {

        return preorder(root);
        
    }
};
