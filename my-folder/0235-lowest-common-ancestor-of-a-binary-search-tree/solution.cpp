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
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root)
        {
            return NULL;
        }
        if(root->val<p->val)
        {
            return lca(root->right,p,q);
        }
        else if(root->val>q->val)
        {
            return lca(root->left,p,q);
        }
        else
            return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val<q->val)
        {
            return lca(root,p,q);
        }
        else
        {
            return lca(root,q,p);
        }



        
    }
};
