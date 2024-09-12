class Solution {
public:
    int rec(vector<vector<int>> &dp,string &s,int l ,int r)
    {
        if(l>=r)
        {
            return 0;
        }
        if(dp[l][r]!=-1)
        {
            return dp[l][r];
        }
        if(s[l]==s[r])
        {
            return dp[l][r]=rec(dp,s,l+1,r-1);
        }
        else
        {
            return dp[l][r]=1+min(rec(dp,s,l+1,r),rec(dp,s,l,r-1));
        }


    }

    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return rec(dp,s,0,n-1);
    }
};
