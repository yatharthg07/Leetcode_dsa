class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++)
        {
            v.push_back(make_pair(nums[i],i));
        }
        sort(v.begin(),v.end());
        int beg=0;
        int end=nums.size()-1;
        vector<int> ans;
        while(beg<end)
        {
            if(v[beg].first+v[end].first==target)
            {
                ans.push_back(v[beg].second);
                ans.push_back(v[end].second);
                return ans;
            }
            else if(v[beg].first+v[end].first<target)
            {
                beg++;
            }
            else
            {
                end--;
            }
        }
        return ans;
    }
};
