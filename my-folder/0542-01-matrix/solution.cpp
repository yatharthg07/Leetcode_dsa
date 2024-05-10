class Solution {
public:
    vector<pair<int,int>> dir =  {{-1,0},{1,0},{0,-1},{0,1}};
    void bfs(vector<vector<int>> &grid,queue<pair<int,int>> &q,int n,int m)
    {
        while(!q.empty())
        {
\
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(auto co:dir)
                {
                    int nx=x+co.first;
                    int ny=y+co.second;
                    if(nx>=0 && nx<n && ny>=0 && ny<m &&grid[nx][ny]==-1)
                    {
                        grid[nx][ny]=grid[x][y]+1;
                        q.push({nx,ny});

                    }

                }

        }

    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue <pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({i,j});
                }
                else
                {
                    mat[i][j]=-1;
                }
            }
        }
        bfs(mat,q,n,m);
        return mat;





    }
};
