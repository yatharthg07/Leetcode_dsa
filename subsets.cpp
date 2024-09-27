class Solution {
public:
    void rec(vector<vector<int>> &ans,vector<int> &temp,vector<int> &nums,int n)
    {
        if(n<0)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[n]);
        rec(ans,temp,nums,n-1);
        temp.pop_back();
        rec(ans,temp,nums,n-1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        rec(ans,temp,nums,n-1);
        return ans;
    }
};