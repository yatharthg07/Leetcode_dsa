/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*> mp;
    void parentf(TreeNode * root, TreeNode* parent)
    {
        if(root==NULL)
        {
            return; 
        }
        mp[root]=parent;
        parentf(root->left,root);
        parentf(root->right,root);

        
    }
    vector<int> ans;
    unordered_set <TreeNode*> visited;
    void dfs(TreeNode* node, int K) {
    if (!node) return;
    if (visited.count(node) > 0) return;
    visited.insert(node);
    if (K == 0) {
        ans.push_back(node->val);
        return;
    }
    dfs(node->left, K - 1);
    dfs(node->right, K - 1);
    dfs(mp[node], K - 1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        parentf(root,NULL);
        dfs(target,k);
        return ans;

        
    }
};
