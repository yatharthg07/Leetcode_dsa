class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        vector<int> curr;
        
        helper(res, curr, nums, 0);
        
        return res;
    }
private:
    void helper(vector<vector<int>>& res, vector<int>& curr, const vector<int>& nums, int pos) {
        if (pos == nums.size()) {
            res.push_back(curr);
            return;
        }
        

        curr.push_back(nums[pos]);
        helper(res, curr, nums, pos + 1);
        curr.pop_back();
        
        while(pos+1<nums.size()&&nums[pos]==nums[pos+1])
        {
            pos+=1;

        }
        helper(res, curr, nums, pos + 1);

        

    }
};
