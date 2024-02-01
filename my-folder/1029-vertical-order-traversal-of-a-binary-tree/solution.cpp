
class Solution {
public:
    vector<pair<pair<int, int>, int>> v;

    void dfs(TreeNode* root, int col, int row) {
        if (root == nullptr) {
            return;
        }
        v.push_back({{col, row}, root->val});
        dfs(root->left, col - 1, row + 1);
        dfs(root->right, col + 1, row + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        dfs(root, 0, 0);
        sort(v.begin(), v.end());

        int i = -1;
        int c = v[0].first.first - 1;

        for (auto it = v.begin(); it != v.end(); ++it) {
            if (it->first.first != c) {
                res.push_back(vector<int>());
                i++;
                res[i].push_back(it->second);
                c = it->first.first;
            } else {
                res[i].push_back(it->second);
            }
        }

        // for (auto& r : res) {
        //     sort(r.begin(), r.end());
        // }
        return res;
    }
};

