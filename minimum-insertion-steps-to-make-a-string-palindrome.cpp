class Solution {
public:
    int minInsertions(string text1) {
        int n1=text1.length();
        string text2=text1;
        reverse(text2.begin(),text2.end());
        int n2=text2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1e9));
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(i==0||j==0)
                {
                    dp[i][j]=0;
                    continue;
                }
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                dp[i][j]=max({dp[i][j],dp[i-1][j],dp[i][j-1]});
            }
        }
        return n1-dp[n1][n2];
        
    }
};