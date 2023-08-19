
class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<int> prev(n+1,0);
        vector<int> cur(n+1,0);
        prev[0]=1;
        cur[0]=1;

        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                cur[j]=prev[j]+cur[j-1];
            }
            prev=cur;
        }
        return cur[n-1];
    }
};

