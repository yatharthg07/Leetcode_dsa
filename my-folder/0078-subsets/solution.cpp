class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int>& nums,vector<int> &res,int idx)
    {
        ans.push_back(res);
        if(idx==nums.size())
        {
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            res.push_back(nums[i]);
            rec(nums,res,i+1);
            res.pop_back();

        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> res;
        int size=nums.size();
        rec(nums,res,0);
        return ans;
    }
};
