class Solution {
public:
    int solve(vector<int> &dp, vector<int> &arr, int i, int n, int k) {
        if (i == n) {
            return 0; 
        }
        
        if (dp[i] != -1) {
            return dp[i];
        }
        
        int currMax = -1e9;
        int ans = -1e9;
        
   
        for (int p = i; p < min(i + k, n); p++) {
            currMax = max(currMax, arr[p]); 
            int temp = currMax * (p - i + 1) + solve(dp, arr, p + 1, n, k);  
            ans = max(ans, temp);  
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);  
        return solve(dp, arr, 0, n, k); 
    }
};
