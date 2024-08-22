class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int ele;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                ele=nums[i];
                cnt++;
            }
            else{
                if(nums[i]==ele)
                {
                    cnt++;

                }
                else
                {
                    cnt--;
                }
            }
        }
        cnt=0;
        for(auto it:nums)
        {
            if(it==ele)
            {
                cnt++;
            }
        }
        if(cnt>nums.size()/2)
        return ele;
        else
        return -1;
        
    }
};
