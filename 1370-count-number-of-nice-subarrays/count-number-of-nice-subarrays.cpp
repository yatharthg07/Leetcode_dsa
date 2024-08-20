class Solution {
public:
    int help(vector<int> & nums,int k)
    {
        int l=0;
        int r=0;
        int n=nums.size();
        int count=0;
        int res=0;
        while(r<n)
        {
            count += nums[r]%2==0?0:1;
            while(count>k)
            {
                count-=nums[l]%2==0?0:1;
                l++;
            }
            res+=r-l+1;
            r++;

        }
        return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
        
    }
};