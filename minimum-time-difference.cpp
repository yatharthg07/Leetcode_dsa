class Solution {
public:
    int helper(string s)
    {
        auto it=s.find(':');
        int min=stoi(s.substr(0,it))*60 + stoi(s.substr(it+1));
        return min;
    }
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        for(auto it:timePoints)
        {
            v.push_back(helper(it));
        }
        int ans=INT_MAX;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size()-1;i++)
        {
            ans=min(ans,v[i+1]-v[i]);
        }
        ans=min(ans,1440-v[v.size()-1]+v[0]);
        return ans;
    }
};