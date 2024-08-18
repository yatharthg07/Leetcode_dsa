class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1,0);
        int i2=1;int i3=1;int i5=1;
        dp[1]=1;
        for(int i=2;i<n+1;i++)
        {
            int num=min({dp[i2]*2,dp[i3]*3,dp[i5]*5});
            dp[i]=num;
            if (num == dp[i2] * 2) i2++;
            if (num == dp[i3] * 3) i3++; 
            if (num == dp[i5] * 5) i5++; 

        }




        return dp[n];
        
    }
};