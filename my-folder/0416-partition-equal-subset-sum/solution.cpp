class Solution {
public:
    int solveHelper(vector<int> &A, int n1, int B, vector<vector<int>>& dp) {
    if (B == 0) {
        return 1;
    } else if (n1 == 0) {
        return 0;
    }

    if (dp[n1][B] != -1) {
        return dp[n1][B];
    }

    if (A[n1 - 1] <= B) {
        return dp[n1][B] = (solveHelper(A, n1 - 1, B - A[n1 - 1], dp) || solveHelper(A, n1 - 1, B, dp));
    } else {
        return dp[n1][B] = solveHelper(A, n1 - 1, B, dp);
    }
}
    bool canPartition(vector<int>& nums) {
        int n=nums.size();

        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2==1)
        {
            return false;
        }
        else
        {
            vector<vector<int>>dp(n+1,vector<int>(sum/2+1,-1));
            return solveHelper(nums,n,sum/2,dp);
        }

        
        
    }


};
