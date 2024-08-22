class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0;
        int r=0;
        int cnt=0;
        int res=0;
        for(int r=0;r<nums.size();r++)
        {
            if(nums[r]==1)
            {
                res=max(++cnt,res);
            }
            else
            {
                cnt=0;
            }
        }
        return res;
        
    }
};