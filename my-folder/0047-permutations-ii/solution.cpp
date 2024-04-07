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
        unordered_set <int> mp;
        for(int i=idx;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
            {


                mp.insert(nums[i]);

            swap(nums[idx],nums[i]);
            rec(nums,size,idx+1);
            swap(nums[idx],nums[i]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
                vector<int> res;
        int size=nums.size();
        rec(nums,size,0);
        return ans;
        
    }
};
