class Solution {
public:
    void rotate(vector<vector<int>>&nums) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                swap(nums[i][j],nums[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                swap(nums[i][j],nums[i][n-1-j]);
            }
        }



        
    }
};