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
    int sum=INT_MIN;
    int maxsum(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int leftsum=max(0,maxsum(root->left));
        int rightsum=max(0,maxsum(root->right));
        // if(leftsum<0)
        // {
        //     sum=max(leftsum+rightsum+root->val,sum);
        // }
        // if(leftsum<0 && rightsum<0)
        // {
        //     sum=max(sum,root->val);
        // }
        // if(leftsum<0)
        // {
        //    sum=max(rightsum+root->val,sum);
        // }
        // else if(rightsum<0)
        // {
        //     sum=max(leftsum+root->val,sum);
        // }
        // else
         sum=max(leftsum+rightsum+root->val,sum);

        // if(leftsum<=0 && rightsum<=0)
        // {
        //     return root->val;
        // }
        return max(leftsum,rightsum)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int dummy=maxsum(root);
        return sum;
        
    }
};
