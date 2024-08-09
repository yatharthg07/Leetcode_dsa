class Solution {
public:
    bool utility(int i,vector<int> &vis,vector<vector<int>>& graph,vector<bool>&col)
    {
        queue <int> q;
        q.push(i);
        col[i]=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto v: graph[node])
            {
                if(!vis[v])
                {
                    col[v]=!col[node];
                    q.push(v);
                    vis[v]=1;
                }
                else{
                    if(col[v]==col[node])
                    {
                        return false;
                    }
                }
            }

        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();

        vector<int> vis(n,0);
        vector<bool> col(n);
        for(int i=0;i<graph.size();i++)
        {
            if(!vis[i])
            {
                if(utility(i,vis,graph,col)==false)
                {
                    return false;

                }
            }
        }
        return true;
        
    }
};
