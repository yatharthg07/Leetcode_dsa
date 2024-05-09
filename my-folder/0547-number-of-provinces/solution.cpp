class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<int>& vis, int i)
    {
	    vis[i]=1;
	    for(int j=0;j<M.size();j++)
		    if(M[i][j]==1 && !vis[j])
			dfs(M,vis,j);
    }   
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int ans=0;
	    if(n==0) return 0;

	    vector<int>vis(n,0);
        for(int i=0;i<n;i++)
	    {
		    if(!vis[i])
		    {
			    ans++;
			    dfs(isConnected,vis,i);
		    }
	    }
	    return ans;
        
        
        
    }
};
