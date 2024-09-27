class Solution {
public:
    vector<vector<int>> ans;
    void rec(vector<int>& nums,vector<int>& res,unordered_map<int,int> &mp,int size)
    {
        if(res.size()==size)
        {
            ans.push_back(res);
            return;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(mp[i]==0)
            {
                if(i>0 && nums[i]==nums[i-1] && !mp[i-1])continue;
                mp[i]=1;
                res.push_back(nums[i]);
                rec(nums,res,mp,size);
                mp[i]=0;
                res.pop_back();
                
            }

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> mp;
        int size=nums.size();
        sort(nums.begin(),nums.end());
        rec(nums,res,mp,size);
        return ans;
        
    }
};