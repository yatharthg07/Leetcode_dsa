class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0;
        int r=0;
        int len=0;
        for(int r=0;r<nums.size();r++)
        {
            if(nums[r]==1)
            {
                len=max(r-l+1,len);
            }
            else
            {
                l=r+1;
            }
        }
        return len;
        
    }
};