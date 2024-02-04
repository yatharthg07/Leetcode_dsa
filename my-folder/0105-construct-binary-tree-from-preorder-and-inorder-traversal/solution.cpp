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

    TreeNode* build(unordered_map<int,int>& pos,vector<int>& preorder, vector<int>& inorder,int sp,int ep,int si,int ei)
    {
        if(si>ei)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[sp]);
        // auto it=find(inorder.begin()+si,inorder.begin()+ei+1,preorder[sp]);
        int ind=pos[preorder[sp]];
        root->left=build(pos,preorder,inorder,sp+1,sp+ind-si,si,ind-1);
        root->right=build(pos,preorder,inorder,sp+ind-si+1,ep,ind+1,ei);

        return root;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        unordered_map<int,int>pos;
        for(int i=0;i<inorder.size();i++)
        {
            pos[inorder[i]]=i;
        }

        return build(pos,preorder,inorder,0,preorder.size()-1,0,preorder.size()-1);
        
    }
};
