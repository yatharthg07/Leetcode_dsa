class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        int flag=0;
        vector<vector<int>> graph(numCourses);
        vector<int> in(numCourses,0);
        for(auto it:prerequisites)
        {
            graph[it[1]].push_back(it[0]);
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
        int cnt=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            cnt++;
            for(auto it:graph[node])
            {
                in[it]--;
                if(in[it]==0)
                {
                    q.push(it);
                }
            }
        }

        if(cnt==numCourses)
        {
            return ans;
        }
        else
        {
            return {};
        }

        
        
    }
};
