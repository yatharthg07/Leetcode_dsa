class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        for(auto it:tasks)
        {
            mp[it]++;
        }
        priority_queue<pair<int,char>> pq;
        for(auto it:mp)
        {
            pq.push({it.second,it.first});
        }
        int t=0;
        queue<tuple<int,int,char>> q;
        while(!pq.empty()||!q.empty())
        {
            if(!q.empty() && get<0>(q.front())==t)
            {
                pq.push({get<1>(q.front()),get<2>(q.front())});
                q.pop();
            }
            if(pq.empty())
            {
                t++;
                continue;
            }

            auto [f,c] = pq.top();
            pq.pop();
            if(f>1)
                q.push({t+n+1,f-1,c});
            t++; 

        }
        return t;
        
    }
};