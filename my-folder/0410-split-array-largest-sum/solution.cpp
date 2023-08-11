class Solution {
public:

    int cnt(vector<int> &a,int m)
    {
        int count=1;
        int sum=0;
        for(int i=0;i<a.size();i++)
        {
            sum+=a[i];
            if(sum>m)
            {
                sum=a[i];
                count++;

            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int h=accumulate(nums.begin(),nums.end(),0);
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(cnt(nums,m)>k)
            {
                l=m+1;
            }
            else
            {
                h=m-1;
            }

        }
        return l;
        
    }
};
