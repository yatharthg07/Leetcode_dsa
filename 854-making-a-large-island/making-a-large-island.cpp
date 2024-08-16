class DisjointSet {
    vector<int> rank, parent, size;
    int max_size = 1;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int root_u = findUPar(u);
        int root_v = findUPar(v);
        if (root_u == root_v) return;
        if (size[root_u] < size[root_v]) {
            parent[root_u] = root_v;
            size[root_v] += size[root_u];
            max_size = max(max_size, size[root_v]);
        }
        else {
            parent[root_v] = root_u;
            size[root_u] += size[root_v];
            max_size = max(max_size, size[root_u]);
        }
    }

    int maxx() {
        return max_size;
    }

    int sizee(int p) {
        return size[p];
    }
};

vector<int> d = {-1, 0, 1, 0, -1};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        auto is_valid = [&](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < n;
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int nodeno = n * i + j;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + d[k], ny = j + d[k + 1];
                        if (is_valid(nx, ny) && grid[nx][ny] == 1) {
                            int adjno = n * nx + ny;
                            ds.unionBySize(nodeno, adjno);
                        }
                    }
                }
            }
        }

        if (ds.maxx() == n * n) return n * n;

        int ans = ds.maxx();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> par;
                    int sum = 1;
                    for (int k = 0; k < 4; k++) {
                        int nx = i + d[k], ny = j + d[k + 1];
                        if (is_valid(nx, ny) && grid[nx][ny] == 1) {
                            int root = ds.findUPar(n * nx + ny);
                            if (par.insert(root).second) {
                                sum += ds.sizee(root);
                            }
                        }
                    }
                    ans = max(ans, sum);
                }
            }
        }

        return ans;
    }
};