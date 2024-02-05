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
    vector<int> ans;
    void preorder(TreeNode *root)
    {
        if(root==NULL)
        {
            return;
        }
        ans.push_back(root->val);
        preorder(root->left);
        preorder(root->right);

    }
    void flatten(TreeNode* root) {
        if(root==NULL)
        {
            return;
        }
        preorder(root);
        TreeNode * LL = root;
        int f=0;
        for(auto it:ans)
        {
            if(f==0)
            {
                f=1;
                continue;
            }
            TreeNode *temp=new TreeNode(it);
            LL->left=NULL;
            LL->right=temp;
            LL=LL->right;

        }

        
    }
};
