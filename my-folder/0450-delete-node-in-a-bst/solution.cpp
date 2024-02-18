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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* cur=root;
        TreeNode* prev=NULL;
        while(cur)
        {           
            if(cur->val==key)
            {
                break;
            }
            prev=cur;
            if(cur->val > key)
            {
                cur=cur->left;
            }
            else
            {
                cur=cur->right;
            }
        }
        if(cur==NULL)
        {
            return root;
        }
        if(!cur->left||!cur->right)
        {
            TreeNode * temp=NULL;
            if(cur->left)
            {
                temp=cur->left;
            }
            else
            {
                temp=cur->right;

            }
            if(prev==NULL)
            {               
                delete(cur);
                return temp;
            }

            if(cur==prev->left)
            {
                prev->left=temp;
            }
            else
            {
                prev->right=temp;
            }
            delete(cur);
        }
        else
        {
            TreeNode * par=cur;
            TreeNode * in=cur->right;
            while(in->left)
            {
                par=in;
                in=in->left;
            }
            cur->val=in->val;
            if(par==cur)
            {
                par->right=in->right;
            }
            else
            {
                par->left=in->right;
            }
            delete(in);





        }
        return root;
        
    }
};
