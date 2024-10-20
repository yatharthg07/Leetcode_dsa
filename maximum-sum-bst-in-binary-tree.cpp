/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class NodeVal {
    public:
    int maxval, minval, sum;
    NodeVal(int maxval, int minval, int sum) {
        this->maxval = maxval;
        this->minval = minval;
        this->sum = sum;
    }
};
int ans = 0;
NodeVal solve(TreeNode* root) {
    if (!root)
        return NodeVal(INT_MIN, INT_MAX, 0);
    auto left = solve(root->left);
    auto right = solve(root->right);
    if (left.maxval < root->val && root->val < right.minval) {
        ans=max(ans,right.sum + left.sum + root->val);
        return NodeVal(max(root->val, right.maxval),
                           min(root->val, left.minval),
                           right.sum + left.sum + root->val);
    }
    return NodeVal(INT_MAX, INT_MIN, max(right.sum, left.sum));
}

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        ans=0;
        solve(root);
        return ans;
    }
};