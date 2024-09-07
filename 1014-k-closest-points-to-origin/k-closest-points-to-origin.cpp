class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<tuple<double,int,int>> pq;
        for(auto it:points)
        {
            pq.push({sqrt((pow(it[0],2)+pow(it[1],2))),it[0],it[1]});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty())
        {
          auto [d,x,y]=pq.top();
            pq.pop();
            ans.push_back({x,y});
        }
        return ans;
        
    }
};