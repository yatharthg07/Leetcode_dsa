class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>> dp(n,vector<int> (n));
        vector<int> curr(n);
        vector<int> prev(n);
        prev[0]=triangle[0][0];
        curr[0]=triangle[0][0];
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                int up=INT_MAX;
                int left=INT_MAX;
                if(j!=0)
                {
                    left=prev[j-1];
                }
                if(j<i)
                {
                    up=prev[j];
                }
                curr[j]=min(up,left)+triangle[i][j];
                
            }
            prev=curr;
        }
        return *min_element(curr.begin(),curr.end());

        
    }
};