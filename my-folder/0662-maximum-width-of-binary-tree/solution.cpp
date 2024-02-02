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
 #include <climits>
class Solution {
public:
    vector<pair<unsigned long long,unsigned long long>> lvl;
    unsigned long long maxc=1;
    void dfs(TreeNode* root, int depth, unsigned long long ind) {
        if (root == nullptr) {
            return;
        }
        if(depth==lvl.size())
        {
            lvl.push_back(pair<unsigned long long,unsigned long long>());
            lvl[depth].first=ind;
        }
        lvl[depth].second=ind;
        dfs(root->left, depth+ 1,2*ind);
        dfs(root->right, depth + 1,2*ind+ 1);
    }
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root,0,0);
        for(auto it:lvl)
        {
            maxc=max(maxc,it.second - it.first+1);
        }      
        return maxc;  
    }

};
