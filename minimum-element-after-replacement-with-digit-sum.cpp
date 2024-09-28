class Solution {
public:
    int uti(int num)
    {
        int sum=0;
        while(num>0)
        {
            sum+=(num%10);
            num=num/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(auto num:nums)
        {
            ans=min(ans,uti(num));

        }
        return ans;
        
    }
};