class Solution {
public:
    int findKthPositive(vector<int>& a, int k) {
        pair<int,int> p;
        p.first=0;
        p.second=0;
        if(a[0]!=1)
        {
            p.first=a[0]-1;
            p.second=a[0]-1;
        }
        if(p.first>k)
        {
            return k;
        }
        for(int i=0;i<a.size()-1;i++)
        {
            if(a[i+1]-a[i]-1+p.first<k)
            {
                p.first=a[i+1]-a[i]-1+p.first;
                p.second=a[i+1]-1;

            }
            else
            {
                if(p.first<k)
                {p.second=a[i]+k-p.first;
                p.first=k;
                break;}
            }
        }
        if(p.first!=k)
        {
            return a[a.size()-1]+k-p.first;
        }
        else
        {
            return p.second;
        }
        
    }
};
