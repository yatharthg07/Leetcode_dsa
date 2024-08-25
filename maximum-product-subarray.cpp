class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int prod=1;
    int ans=INT_MIN;
    for(auto it:nums)
    {
        if(it==0)
        {
             ans=max(ans,0);

            prod=1;
            continue;
        }
        prod*=it;
        ans=max(ans,prod);


    }
    prod=1;
    for(int i=nums.size()-1;i>=0;i--)
    {   
        if(nums[i]==0)
        {
             ans=max(ans,0);

            prod=1;
            continue;
        }
        prod*=nums[i];
        ans=max(ans,prod);

    }
    return ans;

        
    }
};