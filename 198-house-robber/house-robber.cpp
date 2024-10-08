class Solution {
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }

        vector<int>dp(n);
        int first=nums[0];
        int second=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            int curr=max(second,first+nums[i]);
            first=second;
            second=curr;
        }
        return second;


        
    }
};