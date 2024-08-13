class DisjointSet {
    vector<int> rank, parent, size;
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
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};



class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> par;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                if(par.find(accounts[i][j])!=par.end())                
                {    
                    ds.unionByRank(i,ds.findUPar(par[accounts[i][j]]));
                } 
                else
                    par[accounts[i][j]]=i;

            }   
        }

        for(auto it: par)
        {
            par[it.first]=ds.findUPar(par[it.first]);
        }

        unordered_map<int,set<string>> mp;

        for(auto it: par)
        {
            if(mp.find(it.second)!=mp.end())
                mp[it.second].insert(it.first);
            else{
                set<string> tmp;
                tmp.insert(it.first);
                mp[it.second]=tmp;
            }        
        }
        
        vector<vector<string>> ans;
        for(auto it:mp)
        {
            vector<string> tmp;
            tmp.push_back(accounts[it.first][0]);
            for(auto s:it.second)
            {
                tmp.push_back(s);
            }
            ans.push_back(tmp);
        }
    return ans;




        
    }
};