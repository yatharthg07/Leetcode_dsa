class DisjointSet {
    vector<int> rank, parent;
public:
    vector<int> size;
    int maxx=1;
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

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
            size[ulp_u]=1;
            maxx=max(maxx,size[ulp_v]);
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            size[ulp_v]=1;
            maxx=max(maxx,size[ulp_u]);

        }
    }
};

int maxx=10e4;
int maxy=10e4;
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        DisjointSet ds(n);
        unordered_map<int,vector<int>> xcord;
        unordered_map<int,vector<int>> ycord;
        for(int i=0;i<n;i++)
        {
            int x=stones[i][0];
            int y=stones[i][1];
            xcord[x].push_back(i);
            ycord[y].push_back(i);            
        }
        for(auto it:xcord)
        {
            if(it.second.size()==1)
            {
                continue;
            }
            for(int i=0;i<it.second.size()-1;i++)
            {
                ds.unionBySize(it.second[i],it.second[i+1]);
            }
        }

        for(auto it:ycord)
        {
            if(it.second.size()==1)
            {
                continue;
            }
            for(int i=0;i<it.second.size()-1;i++)
            {
                ds.unionBySize(it.second[i],it.second[i+1]);
            }
        }

        int ans=0;
        for(int i=0;i<ds.size.size();i++)
        {
            if(ds.size[i]>1)
            {
                ans+=ds.size[i]-1;
            }
        }
        return ans;


        
    }
};