class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n=cardPoints.size();
        int lsum=0;
        for(int i=0;i<k;i++)
        {
            lsum+=cardPoints[i];
        }
        int maxsum=lsum;
        int r=n-1;
        int rsum=0;
        for(int i=0;i<k;i++)
        {
            lsum-=cardPoints[k-i-1];
            rsum+=cardPoints[r-i];
            maxsum=max(maxsum,lsum+rsum);
        }
        return maxsum;
        
    }
};