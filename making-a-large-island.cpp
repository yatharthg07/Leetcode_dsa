class DisjointSet {
    vector<int> rank, parent, size;
    int max_size=1;
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
            max_size=max(max_size,size[ulp_v]);
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
            max_size=max(max_size,size[ulp_u]);
        }
    }
    int maxx()
    {
        return max_size;
    }
    
    int sizee(int p)
    {
        return size[p];
    }

};

vector<int> d={-1,0,1,0,-1};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                int node=grid[i][j];
                if(node==1)
                {
                    int nodeno= n*i + j;
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+d[k];
                        int ny=j+d[k+1];
                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1)
                        {
                            int adjno=n*nx + ny;
                            if(ds.findUPar(nodeno)!=ds.findUPar(adjno))
                            {
                                ds.unionBySize(nodeno,adjno);
                            }

                        }

                        
                }
                }

            }
        }
        int ans=INT_MIN;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                int node=grid[i][j];
                if(node==0)
                {
                    int sum=1;
                    int nodeno= n*i + j;
                    unordered_set<int> par;
                    for(int k=0;k<4;k++)
                    {
                        int nx=i+d[k];
                        int ny=j+d[k+1];
                        if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==1)
                        {
                            int adjno=n*nx + ny;
                            if(par.find(ds.findUPar(adjno))==par.end())
                            {
                                par.insert(ds.findUPar(adjno));
                            }
                        }
                        
                    }
                    for(auto it:par)
                    {
                        sum+=ds.sizee(it);
                    }
                    ans=max(ans,sum);   
                }

            }
        }

        return ans!=INT_MIN?ans:ds.maxx();

        


        
    }
};