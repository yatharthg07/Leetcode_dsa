class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n=cardPoints.size();
        vector<int> presum(n,0);
        presum[0]=cardPoints[0];
        for(int i=1;i<n;i++)
        {
            presum[i]=presum[i-1]+cardPoints[i];
        }
        int l=0;
        int r=n-1;
        int sum=0;
        int count=0;
        while(l<=r && k>0)
        {
            int lsum = (l > 0) ? presum[l + k - 1] - presum[l - 1] : presum[l + k - 1];
            int rsum = presum[r] - ((r - k >= 0) ? presum[r - k] : 0);
            if(lsum>rsum)
            {
                sum+=cardPoints[l];
                k--;
                l++;
            }
            else
            {
                sum+=cardPoints[r];
                k--;
                r--;
            }

        }
        return sum;
        
    }
};