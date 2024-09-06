class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        int cnt=0;
        sort(intervals.begin(),intervals.end());
        int last=INT_MIN;
        for(auto it:intervals)
        {
            if(it[0]>=last)
            {
                last=it[1];
            }
            else if(it[0]<last && it[1]<=last)
            {
                cnt++;
                last=it[1];
            }
            else if(it[0]<last && it[1]>last)
            {
                cnt++;
            }

        }
        return cnt;
        
    }
};