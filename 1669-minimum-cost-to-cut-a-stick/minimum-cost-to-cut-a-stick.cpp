class Solution {
public:
    int solve(unordered_map<string,int> &mp,vector<int> &cuts,int i,int j)
    {
        string temp=to_string(i)+'-'+to_string(j);
        int ans=1e9;
        if(i>=j)
        {
            return 0;
        }
        if(mp.find(temp)!=mp.end())
        {
            return mp[temp];
        }
        for(int k=0;k<cuts.size();k++)
        {
            if(cuts[k]<j&&cuts[k]>i)
            {
                int res=solve(mp,cuts,i,cuts[k])+solve(mp,cuts,cuts[k],j)+j-i;
                ans=min(res,ans);
            }

        }
         return mp[temp] = (ans == 1e9 ? 0 : ans);
    }
    int minCost(int n, vector<int>& cuts) {
        unordered_map<string,int> mp;
        sort(cuts.begin(),cuts.end());
        return solve(mp,cuts,0,n);
        
    }
};