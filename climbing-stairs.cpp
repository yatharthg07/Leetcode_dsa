class Solution {
       vector<int> dp = vector<int>(46, -1); 
public:

    int rec(int n)
    {
        if(n==0||n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }


        return dp[n]=rec(n-1)+rec(n-2);
    }
    int climbStairs(int n) {

        return rec(n);
        
    }
};