class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    
    int find(int u) {
        if (parent[u] != u) 
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v) {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v) {
            if (rank[root_u] > rank[root_v])
                parent[root_v] = root_u;
            else if (rank[root_u] < rank[root_v])
                parent[root_u] = root_v;
            else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(20000);  // Assume max coordinate is < 10^4

        for (auto& stone : stones) {
            int x = stone[0] + 10000;  // Offset x by 10000 to avoid overlap with y
            int y = stone[1];
            ds.unite(x, y);  // Union x and y coordinates
        }

        unordered_set<int> uniqueParents;
        for (auto& stone : stones) {
            int x = stone[0] + 10000;
            uniqueParents.insert(ds.find(x));
        }

        return n - uniqueParents.size();  // Total stones - number of unique components
    }
};
