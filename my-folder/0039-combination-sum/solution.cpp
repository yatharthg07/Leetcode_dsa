class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& curr,
                const vector<int>& candidates, int target, int pos) {

        if (target == 0) {
            res.push_back(curr);
            return;
        }
        if (pos == candidates.size()) {
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            if (candidates[i] <= target) {

                curr.push_back(candidates[i]);
                helper(res, curr, candidates, target - candidates[i], i);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        helper(res, curr, candidates, target, 0);

        return res;
    }
};
