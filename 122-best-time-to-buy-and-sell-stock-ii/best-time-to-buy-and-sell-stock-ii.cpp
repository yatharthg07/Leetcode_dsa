class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int prev=prices[0];
        int profit=0;
        for(int i=1;i<n;i++)
        {
            if(prices[i]>prev)
            {
                profit+=prices[i]-prev;
                prev=prices[i];
            }
            else
            {
                prev=prices[i];
            }
        }
        return profit;
        
    }
};