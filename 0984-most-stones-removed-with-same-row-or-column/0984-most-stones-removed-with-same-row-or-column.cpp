class DisjointSet {
    vector<int> rank, parent;
public:
    vector<int> size;
    int maxx=1;
    int comp;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        comp=n;
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        comp--;
    }
};

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
        for(int i=0;i<n;i++){
            if(ds.findUPar(i)==i){
                ans+=ds.size[i]-1;
            }
        }
        return ans;

        
    }
};