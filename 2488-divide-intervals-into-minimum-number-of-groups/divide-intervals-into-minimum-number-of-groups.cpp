class Solution {
public:

    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int> ,greater<int>> pq;
        int cnt=0;
        for(auto it:intervals)
        {
            if(pq.empty())
            {
                pq.push(it[1]);
                cnt++;
                continue;
            }
            if(pq.top()<it[0])
            {
                pq.pop();
            }
            else
            {
                cnt++;
            }
            pq.push(it[1]);
        }
        return cnt;
        
    }
};