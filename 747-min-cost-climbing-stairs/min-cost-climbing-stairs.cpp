class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // vector<int> dp(n+1,INT_MAX);
        int first=0;
        int second=0;
        int curr;
        for(int i=2;i<=n;i++)
        {
            curr=min(second+cost[i-1],first+cost[i-2]);
            first=second;
            second=curr;

        }
        return curr;
        
    }
};