class Solution {
public:

    long long count(vector <int> &a,int m)
    {
        long long count=0;
        for(int i=0;i<a.size();i++)
        {
            if(a[i]%m!=0)
            {
                count=count+(a[i]/m)+1;
            }
            else
            {
                count=count+(a[i]/m);
            }
        }
        return count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        int i=1;
        int j=*max_element(piles.begin(),piles.end());
        long long ans=INT_MAX;
        while(i<=j)
        {
            long long mid=i+(j-i)/2;
            if(count(piles,mid)>h)
            {
                i=mid+1;
            }
            else
            {
                j=mid-1;
                ans=min(ans,mid);
            }
        }
        return ans;

        
    }
};
