#define ll long long
class Solution {
public:
    ll rec(vector<int> &a,vector<int>&b,int i,int j,vector<vector<ll>> &dp)
    {
        int n1=a.size();
        int n2=b.size();
        if(n1-i==n2-j)
        {
            ll temp=0;
            while(i<n1)
            {
                temp += (ll)a[i] * (ll)b[j];  
                i++;
                j++;
            }
            return temp;
        }
        if(i==n1)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        return dp[i][j]=max(rec(a,b,i+1,j+1,dp)+(ll)a[i]*(ll)b[j],rec(a,b,i,j+1,dp));  
    }
    
    long long maxScore(vector<int>& a, vector<int>& b) {
        int n1=a.size();
        int n2=b.size();
        vector<vector<ll>> dp(n1+1,vector<ll> (n2+1,-1));
        return rec(a,b,0,0,dp);
    }
};
