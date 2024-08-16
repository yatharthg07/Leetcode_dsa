class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int minv=arrays[0][0];
        int maxv=arrays[0][arrays[0].size()-1];
        int dist=INT_MIN;
        for(int i=1;i<arrays.size();i++)
        {
            int mina=arrays[i][0];
            int maxa=arrays[i][arrays[i].size()-1];
            int dista=abs(mina-maxv);
            int distb=abs(maxa-minv);
            dist=max({dist,dista,distb});
            minv=min(minv,mina);
            maxv=max(maxv,maxa);
        }
        return dist;
        
    }
};