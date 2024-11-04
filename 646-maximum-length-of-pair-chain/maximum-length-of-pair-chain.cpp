class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        vector<int> dp(n,1);
        sort(pairs.begin(),pairs.end(),[](vector<int> a,vector<int> b){
            return a[0]<b[0];
        });
        dp[0]=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(pairs[j][1]<pairs[i][0]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        return dp[n-1];
        
    }
};