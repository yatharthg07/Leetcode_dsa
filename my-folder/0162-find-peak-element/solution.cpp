class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int i=1;
        int n=nums.size();
        int j=n-2;
        if(n==1)
        {
            return 0;
        }
        if(nums[0]>nums[1])
        {
            return 0;
        }
        else if(nums[n-1]>nums[n-2])
        {
            return n-1;
        }
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(nums[mid]>nums[mid-1]&&nums[mid]>nums[mid+1])
            {
                return mid;
            }
            else if (nums[mid]>nums[mid-1] && nums[mid+1]>nums[mid])
            {
                i=mid+1;
            }
            else if (nums[mid]<nums[mid-1] && nums[mid+1]<nums[mid])
            {
                j=mid-1;
            }
            else if(nums[mid]<nums[mid-1]&&nums[mid]<nums[mid+1])

            {
                j=mid-1;
            }
        }
        return -1;

        
    }
};
