#define ll long long

class Solution {
public:
    long long maximumTotalSum(vector<int>& heights) {
        sort(heights.begin(),heights.end(),greater<int>());
        int height=heights[0];
        ll sum=height;
        for(int i=1;i<heights.size();i++)
        {
            height--;
            if(height==0)
            {
                return -1;
            }
            if(height>heights[i])
            {
                height=heights[i];
            }
            sum+=height;
        }
        return sum;

        
    }
};