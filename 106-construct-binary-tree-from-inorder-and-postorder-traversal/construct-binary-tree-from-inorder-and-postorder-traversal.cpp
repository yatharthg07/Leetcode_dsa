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
    TreeNode* build(unordered_map<int,int>& pos,vector<int>& postorder, vector<int>& inorder,int sp,int ep,int si,int ei)
    {
        if(si>ei||sp>ep)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[ep]);
        int posi=pos[postorder[ep]];
        
        root->left=build(pos,postorder,inorder,sp,sp+posi-si-1,si,posi-1);
        root->right=build(pos,postorder,inorder,sp+posi-si,ep-1,posi+1,ei);

        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int>pos;
        for(int i=0;i<inorder.size();i++)
        {
            pos[inorder[i]]=i;
        }

        return build(pos,postorder,inorder,0,inorder.size()-1,0,inorder.size()-1);
        
    }
};

// class Solution {
// public:
//     TreeNode* build(unordered_map<int,int>& pos, vector<int>& postorder, vector<int>& inorder, int sp, int ep, int si, int ei) {
//         if (si > ei || sp > ep) {
//             return NULL;
//         }
//         TreeNode* root = new TreeNode(postorder[ep]);
//         int left = pos[postorder[ep]] - si;
        
//         root->left = build(pos, postorder, inorder, sp, sp + left - 1, si, si + left - 1);
//         root->right = build(pos, postorder, inorder, sp + left, ep - 1, si + left + 1, ei);

//         return root;
//     }

//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         unordered_map<int,int> pos;
//         for (int i = 0; i < inorder.size(); i++) {
//             pos[inorder[i]] = i;
//         }

//         return build(pos, postorder, inorder, 0, postorder.size() - 1, 0, inorder.size() - 1);
//     }
// };