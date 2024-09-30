class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,int>> mp(256,{0,0});
        for(auto c:s)
        {
            mp[c].first++;
            mp[c].second=c;
        }
        sort(mp.begin(),mp.end(),greater<pair<int,int>>());
        string ans;
        for(auto it:mp)
        {
            if(it.first==0)
            {
                break;
            }
            while(it.first--)
                ans.push_back(char(it.second));
        }
        return ans;
        
    }
};