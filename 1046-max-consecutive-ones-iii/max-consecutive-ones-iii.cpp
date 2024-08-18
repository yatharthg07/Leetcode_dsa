class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int r=0;
        int maxlen=0;
        int count=0;
        while(r<n)
        {

            if(nums[r]==0)
            {
                count++;
            }
            if(count>k && l<=r)
            {
                if(nums[l]==0)
                {
                    count--;
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};