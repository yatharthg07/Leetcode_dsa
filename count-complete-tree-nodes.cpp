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
    int leftheight(TreeNode* root)
    {
        int cnt=0;
        while(root!=NULL){
            root=root->left;
            cnt++;
        }
        return cnt;
    }
    int rightheight(TreeNode* root)
    {
        int cnt=0;
        while(root!=NULL){
            root=root->right;
            cnt++;
        }
        return cnt;
    }
    int rec(TreeNode* root)
    {
        if(root==NULL)return 0;
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh) return (pow(2,lh)-1);
        else return 1+rec(root->left)+rec(root->right);
    }
    int countNodes(TreeNode* root) {
        return rec(root);

    }
};