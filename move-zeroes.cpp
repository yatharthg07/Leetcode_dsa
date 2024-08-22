class Solution {
public:
    void moveZeroes(vector<int>& nums) {

            int l=0;
            int r=0;
            int n=nums.size();
            while(r<n && l<n)
            {
                if(nums[l]!=0)
                {
                    l++;
                    continue;
                }
                if(nums[r]==0)
                {
                    r++;
                    continue;
                }
                if(l<r)
                    swap(nums[r],nums[l]);
                else
                {
                    swap(l,r);
                }    
                l++;
                r++;

            }
        
    }
};