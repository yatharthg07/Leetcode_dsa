class Solution {
public:

    int count(vector <int> &a,int mid,int k)
    {
        int cnt=0;
        int cons=0;
        for(int i:a)
        {
            if(i<=mid)
            {
                cons++;
                if(cons==k)
                {
                    cnt ++;
                    cons=0;
                }
            }
            else
            {
                cons=0;
                continue;
            }
        }
        return cnt;
    }
    int minDays(vector<int>& a, int m, int k) {
        int i=1;
        int j=*max_element(a.begin(),a.end());
        int ans=INT_MAX;

        while(i<=j)
        {
            int mid=i+(j-i)/2;
            if(count(a,mid,k)>=m)
            {
                j=mid-1;
                ans=min(ans,mid);
            }
            else
            {
                i=mid+1;

            }
            
            
        }
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
        
    }
};
