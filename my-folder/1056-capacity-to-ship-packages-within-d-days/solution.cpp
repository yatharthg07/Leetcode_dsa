class Solution {
public:
    int count(vector<int>& weights,int m)
    {
        int c=0;
        int sum=0;
        for(int i=0;i<weights.size();i++)
        {
            sum+=weights[i];
            if(sum>m)
            {
                c++;
                sum=weights[i];
            }

        }
        return c+1;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int l=*max_element(weights.begin(),weights.end());
        int h=accumulate(weights.begin(),weights.end(),0);
        int ans=INT_MAX;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(count(weights,m)>days)
            {
                l=m+1;
            }
            else
            {
                h=m-1;
                ans=min(ans,m);
            }
        }
        return ans;

        
    }
};
