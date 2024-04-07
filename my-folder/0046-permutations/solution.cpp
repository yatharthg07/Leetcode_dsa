class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int>& nums,int size,int idx)
    {
        if(idx==size)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=idx;i<nums.size();i++)
        {
            swap(nums[idx],nums[i]);
            rec(nums,size,idx+1);
            swap(nums[idx],nums[i]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<int> res;
        int size=nums.size();
        rec(nums,size,0);
        return ans;

        
    }
};
