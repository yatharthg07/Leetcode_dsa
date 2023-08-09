class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int ans=nums[0];
        while(i<j)
        {
            int mid=i+(j-i)/2;

            if(nums[j]<nums[mid])
            {

                    i=mid+1;

            }
            else if(nums[j]>nums[mid])
            {
                    j=mid;
            }
            else
            {
                j--;
            }
        }
        return nums[i];
        
    }
};
