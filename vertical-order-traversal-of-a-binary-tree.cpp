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
    map<pair<int,int>,vector<int>> mp;
    void trav(TreeNode* root,int row,int col)
    {
        if(root==NULL)
        {
            return;
        }
        mp[{col,row}].push_back(root->val);
        trav(root->left,row+1,col-1);
        trav(root->right,row+1,col+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        trav(root,0,0);
        map<int,vector<int>> ans;
        for(auto it:mp)
        {
            vector<int> temp=it.second;
            sort(temp.begin(),temp.end());
            for(auto num:temp)
            {
                ans[it.first.first].push_back(num);
            }
        }
        vector<vector<int>> res;
        for(auto it:ans)
        {
            res.push_back(it.second);
        }
        return res;


        
    }
};