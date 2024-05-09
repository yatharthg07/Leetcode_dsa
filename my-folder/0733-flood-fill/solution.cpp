class Solution {
public:
        vector<pair<int,int>> dir =  {{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>> &grid,int n,int m,int color,int val,int i,int j)
    {
        if(i<0 || i>=n || j<0 || j>=m ||grid[i][j]!=val)
        {
            return;
        }
        grid[i][j]=color;
        for(auto co:dir)
        {
            int nx=i+co.first;
            int ny=j+co.second;
            dfs(grid,n,m,color,val,nx,ny);

        }


    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        int val=image[sr][sc];
        if(val==color)
        {
            return image;
        }
        dfs(image,n,m,color,val,sr,sc);
        return image;

    }
};
