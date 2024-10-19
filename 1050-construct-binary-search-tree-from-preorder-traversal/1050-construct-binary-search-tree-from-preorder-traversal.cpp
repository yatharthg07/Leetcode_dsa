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
    int idx=0;
    TreeNode* solve(vector<int>& preorder,int ub)
    {
        if(idx==preorder.size()) return NULL;
        if(preorder[idx]>ub) return NULL;
        auto newnode=new TreeNode(preorder[idx++]);
        newnode->left=solve(preorder,newnode->val);
        newnode->right=solve(preorder,ub);
        return newnode;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,INT_MAX);
    }
};