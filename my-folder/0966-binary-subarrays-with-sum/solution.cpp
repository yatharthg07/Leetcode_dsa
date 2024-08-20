class Solution {
public:
    int help(vector<int>& nums,int goal)
    {
        if(goal<0)
        {
            return 0;
        }
        int n=nums.size();
        int l=0;
        int r=0;
        int sum=0;
        int count=0;
        while(r<n)
        {
            sum+=nums[r];
            while(sum>goal)
            {
                sum-=nums[l];
                l++;
            }
            count+=r-l+1;
            r++;

        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return help(nums,goal)-help(nums,goal-1);
        
    }
};
