class Solution {
public:

    void dfs(int node, int parent, vector<int> &discT, vector<int> &low, unordered_map< int, bool > &visited, vector<vector<int>> &result, unordered_map<int, list <int> > &adj, int &timer)
{
    visited[node] = true;
    discT[node] = low[node] = timer++;
    
    for(auto neighbour : adj[node])
    {
        if(neighbour == parent)
        {
            continue;
        }
        if(!visited[neighbour])
        {
            dfs(neighbour, node, discT, low, visited, result, adj, timer);
            low[node] =min(low[node], low[neighbour]);
            
            if(low[neighbour] > discT[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        else
        {
             low[node] = min(low[node], discT[neighbour]);
        }
    }
    
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
    unordered_map<int, list <int> > adj;
    for(int i = 0; i<edges.size(); i++)
        {
          int u = edges[i][0];
          int v = edges[i][1];

          adj[u].push_back(v);
          adj[v].push_back(u);
        }
    int timer = 0;
    vector<int> discT(n,-1);
    vector<int> low(n,-1);
    int parent = -1;
    unordered_map< int, bool > visited;
    vector<vector<int>> result;
    for(int i = 0; i < n; i++)
        {
          if(!visited[i])
          {
            dfs(i, parent, discT, low, visited, result, adj, timer);
          }
        }
    return result;
    }
};