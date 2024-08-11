class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& grid) {
        vector<int> cord={-1,0,1,0,-1};
        int n = grid.size();
        int m=grid[0].size();
        // if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
        //     return -1;
        // }
        vector<vector<int>> dist (n,vector<int> (m,INT_MAX));
        // for (int i = 0; i < grid.size(); i++) {
        //     for (int j = 0; j < grid.size(); j++) {
        //         if (grid[i][j] == 0) {
        //             mp[{i, j}] = INT_MAX;
        //         }
        //     }
        // }
        dist[0][0] = 0;
        priority_queue<pair<int,pair<int, int>>, // The type of the elements
        vector<pair<int,pair<int, int>>>, // The underlying
                                                              // container
                                                              // (vector)
        greater<pair<int,pair<int, int>>> // Comparator for
                                                              // min-heap
            >
            q;
        q.push({0,{0, 0}});
        while (!q.empty()) {
            int cordx = q.top().second.first;
            int cordy = q.top().second.second;
            int dists = q.top().first;
            q.pop();
            if(cordx==n-1 && cordy==m-1)
            {
                return dists;
            }
            if (dists != dist[cordx][cordy]) {
                continue;
            }
            for (int i = 0; i <cord.size()-1; i++) {
                    int newx = cordx + cord[i];
                    int newy = cordy + cord[i+1];
                    if (newx >= 0 && newx < n && newy >= 0 && newy < m ) {
                        if (max(dists,abs(grid[newx][newy]-grid[cordx][cordy])) < dist[newx][newy]) {
                            dist[newx][newy] = max(dists,abs(grid[newx][newy]-grid[cordx][cordy]));
                            q.push({dist[newx][newy],{newx, newy}});
                        }
                    }
                }
        }
        if (dist[n - 1][ m - 1] != INT_MAX)
            return dist[n - 1][m - 1] ;
        else
            return -1;
        
    }
};