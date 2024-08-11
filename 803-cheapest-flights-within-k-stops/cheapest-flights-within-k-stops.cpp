class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> graph(n);
        for (auto it : flights) {
            graph[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        // priority_queue<pair<int, pair<int, int>>,
        //                vector<pair<int, pair<int, int>>>,
        //                greater<pair<int, pair<int, int>>>>
        //     q;
        queue <pair<int, pair<int, int>>> q;
        q.push({0, {0, src}});
        int ans=INT_MAX;
        while (!q.empty()) {
            auto top = q.front();
            int lvl = top.first;
            int dists = top.second.first;
            int node = top.second.second;
            if (node == dst&& lvl <= k + 1) {
                ans=min(ans,dists);
            }
            q.pop();

            // if (dists != dist[node]) {
            //     continue;
            // }
            for (auto it : graph[node]) {
                int adj = it.first;
                int cost = it.second;
                if (dists + cost < dist[adj]) {
                    dist[adj] = dists + cost;
                    q.push({1 + lvl, {dist[adj], adj}});
                }
            }
        }
        // if (dist[n - 1][ n - 1] != INT_MAX)
        //     return dist[n - 1][n - 1] + 1;
        // else
        if(ans!=INT_MAX)
        {
            return ans;

        }
        else
        {
            return -1;
        }
        
    }
};