class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph2) {
        int n=graph2.size();
        vector<int> ans;
        vector<vector<int>> graph(n);
        vector<int> in(n,0);


        for(int i=0;i<n;i++)
        {
            for(auto v:graph2[i])
            {
                graph[v].push_back(i);
            }
        }
        for(auto it:graph)
        {
            for(auto v:it)
            {
                in[v]++;
            }

        }
        queue<int> q;

        for(int i=0;i<in.size();i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:graph[node])
            {
                in[it]--;
                if(in[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());

        return ans;

    }
};
