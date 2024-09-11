class Solution {
public:
    int maxArea(vector<int>&arr) {
        int n=arr.size();
        int l=0;
        int r=n-1;
        int ans=INT_MIN;
        while(l<=r)
        {
            ans=max(ans,min(arr[l],arr[r])*(r-l));
            if(arr[l]<arr[r])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
        
    }
};