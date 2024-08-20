class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int hehe=0;
        for(int i=0;i<n;i++)
        {
            if(nums[(i+1)%n]<nums[i])
            {
                hehe++;
            }
            if(hehe>=2)
            {
                return false;
            }
        }
        return true;
        
    }
};