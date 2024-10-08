class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) {
            return -1;
        }
        vector<vector<int>> dist (n,vector<int> (n,INT_MAX));
        // for (int i = 0; i < grid.size(); i++) {
        //     for (int j = 0; j < grid.size(); j++) {
        //         if (grid[i][j] == 0) {
        //             mp[{i, j}] = INT_MAX;
        //         }
        //     }
        // }
        dist[0][0] = 0;
        queue <pair<int,pair<int, int>>> q;
        q.push({0,{0, 0}});
        while (!q.empty()) {
            int cordx = q.front().second.first;
            int cordy = q.front().second.second;
            if(cordx==n-1 && cordy==n-1)
            {
                return dist[n - 1][n - 1] + 1;
            }
            int dists = q.front().first;
            q.pop();

            if (dists != dist[cordx][cordy]) {
                cout<<"hehe";
                continue;
            }
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int newx = cordx + i;
                    int newy = cordy + j;
                    if (newx >= 0 && newx < n && newy >= 0 && newy < n &&
                        grid[newx][newy] == 0) {
                        if (1 + dists < dist[newx][newy]) {
                            dist[newx][newy] = 1 + dists;
                            q.push({1 + dists,{newx, newy}});
                        }
                    }
                }
            }
        }
        // if (dist[n - 1][ n - 1] != INT_MAX)
        //     return dist[n - 1][n - 1] + 1;
        // else
            return -1;
    }
};