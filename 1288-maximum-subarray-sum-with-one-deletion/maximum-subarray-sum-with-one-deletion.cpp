class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int> (2,-1e9));
        dp[0][1]=arr[0];
        for(int i=1;i<n;i++){
            dp[i][1]=max(dp[i-1][1]+arr[i],arr[i]);
            dp[i][0]=max({dp[i-1][0]+arr[i],dp[i-1][1],arr[i]});
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max({ans,dp[i][0],dp[i][1]});
        }
        return ans;

    }
};