class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        vector<double> prob(n,0.0);
        for(int i=0;i<edges.size();i++)
        {
            double prob=succProb[i];
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<pair<double, int>> q;
        prob[start_node]=1.0;
        q.push({1.0,start_node});
        while(!q.empty())
        {
            int node=q.top().second;
            double dist=q.top().first;
            q.pop();
            if(dist<prob[node])
            {
                continue;
            }
            for(auto it:adj[node])
            {
                if(dist*it.second>prob[it.first])
                {
                    prob[it.first]=dist*it.second;
                    q.push({prob[it.first],it.first});
                }
            }
        }
        return prob[end_node];


    }
};