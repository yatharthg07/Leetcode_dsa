class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n=nums.size();
        int profit=0;
        int cheap=nums[0];
        for(int i=0;i<n;i++)
        {
            if(nums[i]<cheap)
            {
                cheap=nums[i];
            }
            profit=max(profit,nums[i]-cheap);
        }
        return profit;
        
    }
};