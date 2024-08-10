class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n=grid.size();
        if(grid[0][0]!=0||grid[n-1][n-1]!=0)
        {
            return -1;
        }
        map<pair<int, int>, int> mp;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid.size();j++)
            {
                if(grid[i][j]==0)
                {
                    mp[{i,j}]=INT_MAX;
                }
            }
        }
        mp[{0,0}]=0;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        while(!q.empty())
        {
            int cordx=q.front().first.first;
            int cordy = q.front().first.second;
            int dist=q.front().second;
            q.pop();

            if(dist!=mp[{cordx,cordy}])
            {
                continue;
            }
            for(int i=-1;i<=1;i++)
            {
                for(int j=-1;j<=1;j++)
                {
                    int newx=cordx+i;
                    int newy=cordy+j;
                    if(newx>=0&& newx<n && newy>=0&& newy<n && grid[newx][newy]==0)
                    {
                        if(1+dist<mp[{newx,newy}])
                        {
                            mp[{newx,newy}]=1+dist;
                            q.push({{newx,newy},1+dist});
                        }
                    }
                }
            }
        }
        if(mp[{n-1,n-1}]!=INT_MAX)
        return mp[{n-1,n-1}]+1;
        else
        return -1;
        
    }
};