class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> temp;
        for(auto it:nums)
        {
            if(lower_bound(temp.begin(),temp.end(),it)==temp.end())
            {
                temp.push_back(it);
            }
            else
            {
                temp[lower_bound(temp.begin(),temp.end(),it)-temp.begin()]=it;
            }
        }
        return temp.size();
        
    }
};