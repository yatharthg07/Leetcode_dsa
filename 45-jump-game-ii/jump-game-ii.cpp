class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        int l=0;
        int r=0;
        int jump=0;
        int farthest=0;
        while(l<n && r<n)
        {
            farthest=l;
            for(int i=l;i<=r;i++)
            {
                farthest=min(n-1,max(farthest,i+nums[i]));

            }
            jump++;
            l=r+1;
            r=farthest;
            if(r==n-1)
            {
                return jump;
            }
        }

        return jump;        
    }
};