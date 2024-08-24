class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i && nums[i]==nums[i-1])
            {
                continue;
            }
            int l=i+1;
            int r=n-1;
            int target=-nums[i];
            while(l<r)
            {
                if(nums[l]==nums[l-1]&& l!=i+1)
                {
                    l++;
                }
                else if(r!=n-1 && nums[r]==nums[r+1] )
                {
                    r--;
                }
                else if(nums[l]+nums[r]<target)
                {
                    l++;
                }
                else if(nums[l]+nums[r]>target)
                {
                    r--;
                }
                else
                {
                    ans.push_back({nums[l],nums[r],nums[i]});
                    l++;
                    r--;
                    
                }

            }

        }
        return ans;
        
    }
};