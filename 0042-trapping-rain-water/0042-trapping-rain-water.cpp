class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> ans(n,0);
        vector<int> left(n,-1);
        vector<int> right(n,-1);
        int lg=-1;
        int rg=-1;
        for(int i=n-1;i>=0;i--)
        {   
            if(height[i]>rg)
            {
                rg=height[i];
            }
            else if(rg>height[i])
            {
                right[i]=rg;
            }
        }
        for(int i=0;i<n;i++)
        {   
            if(height[i]>lg)
            {
                lg=height[i];
            }
            else if(lg>height[i])
            {
                left[i]=lg;
            }
        }

        for(int i=0;i<n;i++)
        {
            if(left[i]==-1||right[i]==-1)
            {
                continue;
            }
            ans[i]=min(left[i],right[i])-height[i];
        }
        return accumulate(ans.begin(),ans.end(),0);
        
    }
};