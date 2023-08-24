class Solution {
public:
    int longestConsecutive(vector<int>& nums) { 
        if(nums.size()==0)
        {
            return 0;
        }
        unordered_set<int> ans(nums.begin(),nums.end());
        int res=INT_MIN;
        for(auto num:nums)
        {
            int count=1;
            if(ans.find(num-1)==ans.end())
            {
                num++;
                while(ans.find(num)!=ans.end())
                {
                    count++;
                    num++;
                }
                res=max(count,res);


            }
            else
            {
                continue;
            }
        }


        return res;
        }
};
