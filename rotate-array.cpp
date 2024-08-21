class Solution {
public:
    void reverse(int idx,int end ,vector<int> & nums)
    {
        for(int i=idx;i<(idx+end+1)/2;i++)
        {
            swap(nums[i],nums[end-(i-idx)]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
        {
            return ;
        }
        if(k>n)
        {
            k=k%n;
        }
        reverse(0,n-1,nums);
        reverse(0,k-1,nums);
        reverse(k,n-1,nums);
        
    }
};