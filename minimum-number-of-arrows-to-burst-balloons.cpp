class Solution {
public:
    static bool compare(const vector<int>&a,const vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end(),compare);
        int cnt=0;
        int i=0;
        long long last=LONG_LONG_MIN;
        while(i<n)
        {
            while(i<n && points[i][0]<=last)
            {
                i++;
            }
            if(i==n)
            
            {
                continue;
            }
            last=points[i][1];
            cnt++;
            i++;
            
        }
        return cnt;
        
    }
};