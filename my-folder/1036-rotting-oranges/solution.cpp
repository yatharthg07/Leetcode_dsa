class Solution {
public:
    vector<pair<int,int>> dir =  {{-1,0},{1,0},{0,-1},{0,1}};
    int bfs(vector<vector<int>> &grid,queue<pair<int,int>> &q,int n,int m)
    {
        int time=-1;
        if(q.empty())
        {
            return 0;
        }
        while(!q.empty())
        {
            time++;
            int sz=q.size();
            for(int i=0;i<sz;i++)
            {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto co:dir)
                {
                    int nx=x+co.first;
                    int ny=y+co.second;
                    if(nx>=0 && nx<n && ny>=0 && ny<m &&grid[nx][ny]==1)
                    {
                        grid[nx][ny]=2;
                        q.push({nx,ny});

                    }

                }


            }
        }
        return time;

    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue <pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        int time= bfs(grid,q,n,m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }

        return time;
        
    }
};
