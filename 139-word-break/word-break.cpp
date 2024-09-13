class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n =s.size();
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<bool> dp(n+1,0);
        dp[0]=true;
        string temp;
        for(int i=1;i<=n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                temp=s.substr(j,i-j);
                if(st.find(temp)!=st.end())
                {
                    if(j==0)
                    {
                        dp[i]=true;
                    }
                    else
                    {
                        dp[i]=dp[j]||dp[i];
                    }
                }
            }
        }
        return dp[n];
        
    }
};