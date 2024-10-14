class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        int pro=1;
        int res=0;
        while(j<n)
        {
            pro*=nums[j];
            while(pro>=k && i<=j) 
            {
                pro/=nums[i];
                i++;
            }
            res+=(j-i+1);
            j++;
        }
        return res;
        
    }
};