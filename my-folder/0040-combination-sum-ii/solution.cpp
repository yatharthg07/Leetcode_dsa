class Solution {
public:
    void helper(vector<vector<int>>& res, vector<int>& curr, const vector<int>& candidates, int target,int pos) {
        
        if (target==0) {
            res.push_back(curr);
            return;
        }
        if(pos==candidates.size())
        {
            return;
        }
        
        if(candidates[pos]<=target)
        {

        
        curr.push_back(candidates[pos]);
        helper(res, curr, candidates,target-candidates[pos], pos+1);
        curr.pop_back();
        }
        while(pos+1<candidates.size()&&candidates[pos]==candidates[pos+1])
        {
            pos+=1;

        }

        helper(res, curr, candidates,target, pos + 1);

        

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

     
        vector<vector<int>> res;
        vector<int> curr;
           sort(candidates.begin(),candidates.end());
        helper(res, curr, candidates, target,0);
        
        return res;
    }
};
