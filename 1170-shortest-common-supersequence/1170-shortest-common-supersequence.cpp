class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        int n1=text1.length();
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
        int i=n1;
        int j=n2;
        string ans;
        while(i>0 && j>0)
        {
            if(text1[i-1]==text2[j-1])
            {
                ans.push_back(text1[i-1]);
                i--;
                j--;

            }
            else if(dp[i-1][j]>dp[i][j-1])
            {   
                ans.push_back(text1[i-1]);
                i--;
            }
            else
            {
                ans.push_back(text2[j-1]);
                j--;
            }
        }

        while(i>0)
        {
            ans.push_back(text1[i-1]);
            i--;
        }
        while(j>0)
        {
            ans.push_back(text2[j-1]);
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;

        
    }
};