class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> st;
        for(int i=0;i<n;i++)    
        {
            if(st.find(target-nums[i])!=st.end())
            {
                return {i,st[target-nums[i]]};
            }
            st[nums[i]]=i;
        }
        return {};
        
    }
};