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

            if (dists != dist[cordx][cordy]) {
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
        if (dist[n - 1][ n - 1] != INT_MAX)
            return dist[n - 1][n - 1] + 1;
        else
            return -1;
    }
};