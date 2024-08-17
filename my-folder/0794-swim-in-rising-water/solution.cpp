class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<int> cord = {-1, 0, 1, 0, -1};
        int n = grid.size();
        vector<vector<int>> dist (n,vector<int> (n,INT_MAX));
        dist[0][0] = grid[0][0];
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            q;
        q.push({grid[0][0],{0,0}});
        while(!q.empty())
        {
            int cordx = q.top().second.first;
            int cordy = q.top().second.second;
            int dists = q.top().first;
            q.pop();
            if(cordx==n-1 && cordy==n-1)
            {
                return dists;
            }
            if (dists != dist[cordx][cordy]) {
                continue;
            }
            for (int i = 0; i <cord.size()-1; i++) {
                    int newx = cordx + cord[i];
                    int newy = cordy + cord[i+1];
                    if (newx >= 0 && newx < n && newy >= 0 && newy < n ) {
                        if (max(dists,grid[newx][newy]) < dist[newx][newy]) {
                            dist[newx][newy] = max(dists,grid[newx][newy]);
                            q.push({dist[newx][newy],{newx, newy}});
                        }
                    }
                }
        }
        if (dist[n - 1][ n - 1] != INT_MAX)
            return dist[n - 1][n - 1] ;
        else
            return -1;


    }
};
