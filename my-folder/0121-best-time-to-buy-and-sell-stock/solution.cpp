class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=1;
        int ans=0;
        if(prices.size()==1)
        {
            return 0;
        }
        while(l!=prices.size()&&r!=prices.size())
        {
            ans=max(ans,prices[r]-prices[l]);
            if(prices[r]<prices[l])
            {
                
                l=r;
                r++;
                            
            }
            else
            {
                
                r++;
                            
            }

            


        }
        return ans;

        
        
    }
};
