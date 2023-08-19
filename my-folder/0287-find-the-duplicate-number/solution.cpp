class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int index=0;
        while(1)
        {  
            if(nums[index]<0)
            {
                return index;
            }
            nums[index]*=-1;
            index=abs(nums[index]);
        }
        return -1;
    }
};
