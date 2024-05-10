class Solution {
public:
    vector<pair<int,int>> dir =  {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int n,int m,int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>=m ||vis[i][j]==1||grid[i][j]=='X')
        {
            return;
        }
        vis[i][j]=1;
        for(auto co:dir)
        {
            int nx=i+co.first;
            int ny=j+co.second;
            dfs(grid,vis,n,m,nx,ny);

        }


    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int j=0;j<m;j++)
        {
            if(board[0][j]=='O')
            {
                dfs(board,vis,n,m,0,j);
            }
            if(board[n-1][j]=='O')
            {
                dfs(board,vis,n,m,n-1,j);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(board[i][0]=='O')
            {
                dfs(board,vis,n,m,i,0);
            }
            if(board[i][m-1]=='O')
            {
                dfs(board,vis,n,m,i,m-1);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O'&&vis[i][j]==0)
                {
                    board[i][j]='X';
                }
            }
        }
    }
};
