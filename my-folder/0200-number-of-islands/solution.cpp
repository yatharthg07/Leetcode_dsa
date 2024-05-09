class Solution {
public:
    vector<pair<int,int>> dir =  {{-1,0},{1,0},{0,-1},{0,1}};
    void bfs(vector<vector<char>> &grid,queue<pair<int,int>> &q,vector<vector<int>> &vis,int n,int m)
    {
        while(!q.empty())
        {
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto co:dir)
                {
                    int nx=x+co.first;
                    int ny=y+co.second;
                    if(nx>=0 && nx<n && ny>=0 && ny<m &&grid[nx][ny]=='1'&&vis[nx][ny]==0)
                    {
                        vis[nx][ny]=1;
                        q.push({nx,ny});

                    }

                }


            }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        queue <pair<int,int>> q;
        int ans=0;    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' &&vis[i][j]==0)
                {
                    ans++;
                    q.push({i,j});
                    vis[i][j]=1;
                    bfs(grid,q,vis,n,m);
                }
            }
        }


        return ans;
        
    }
        
};
