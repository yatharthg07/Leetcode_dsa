class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int l=0;
        for(int r=0;r<nums.size();r++)
        {
            if(nums[r]!=0&& nums[l]==0)
            {
                swap(nums[r],nums[l]);
            }
            if(nums[l]!=0)
            {
                l++;
            }
        }
    }
    
};