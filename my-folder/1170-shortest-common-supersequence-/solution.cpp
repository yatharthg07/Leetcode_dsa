class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        		int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    
                    
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    
                }
            }
            
        }
        string an;
        int i=n;
        int j=m;
        while(i>0&&j>0)
        {
        	if(text1[i-1]==text2[j-1])
        	{
        		an.push_back(text1[i-1]);
        		i--;
        		j--;
 
        	}
        	else
        	{
        		if(dp[i-1][j]>dp[i][j-1])
        		{
                    an.push_back(text1[i-1]);

        			i--;
        		}
        		else
        		{
                    an.push_back(text2[j-1]);
        			j--;
        		}
        	}
        }
        while(i>0)
        {
            an.push_back(text1[i-1]);
            i--;

        }
        while(j>0)
        {
            an.push_back(text2[j-1]);
            j--;

        }
        reverse(an.begin(),an.end());
        return an;
        
    }
};
