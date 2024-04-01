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
    int flag=0;
    TreeNode* temp1;
    TreeNode* temp2;
    TreeNode* prev=NULL;
    void inorder(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left);
        if(prev)
        {
            if(root->val<prev->val)
            {
                if(flag==0)
                {
                    temp1=prev;
                    temp2=root;
                    flag++;
                }
                else
                {
                    temp2=root;
                }
            }

        }
        prev=root;
        inorder(root->right);
        


    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(temp1->val,temp2->val);

        
    }
};
