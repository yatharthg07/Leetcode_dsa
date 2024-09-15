class Solution {
public:
    bool ispal(string &s,int i,int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return 0;
            }
            i++;
            j--;
        }
        

        return 1;
    }

    int solve(vector<vector<int>> &dp,string &s,int i,int j)
    {
        if(i>=j)
        {
            return dp[i][j]=0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(ispal(s,i,j))
        {
            return dp[i][j]=0;
        }
        int ans=1e9;
        for(int k=i;k<j;k++)
        {
            int temp=solve(dp,s,i,k)+solve(dp,s,k+1,j)+1;
            ans=min(temp,ans);
        }
        return dp[i][j]=ans;
    }
    int minCut(string s) {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(dp,s,0,n-1);


        
    }
};