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
class Solution {
public:
    int ans=INT_MIN;
    int time(TreeNode* root, int start) {
        if (root == NULL) {
            return 0;
        }
        int lh = time(root->left,start);
        int rh = time(root->right,start);
        if (root->val == start) {
            ans = max(ans, max(lh, rh));
            return -1;
        } else if (lh >= 0 && rh >= 0) {
            return max(lh, rh) + 1;
        } else {
            int tans = lh < 0 ? abs(lh) + rh : abs(rh) + lh;
            ans=max(ans,tans);
            return min(lh, rh) - 1;
        }
    }
    int amountOfTime(TreeNode* root, int start) { 
        time(root,start);
        return ans; }
};
