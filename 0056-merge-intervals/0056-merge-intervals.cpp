class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        map<int,int> mp;
        for(auto it:intervals)
        {
            mp[it[0]]=max(mp[it[0]],it[1]);
        }
        int start = mp.begin()->first;
        int last = mp.begin()->second;
        for(auto it:mp)
        {
            if(it.first>last)
            {
                ans.push_back({start,last});
                start=it.first;
            }
            last=max(last,it.second);

        }
        ans.push_back({start,last});

        return ans;
        
    }
};