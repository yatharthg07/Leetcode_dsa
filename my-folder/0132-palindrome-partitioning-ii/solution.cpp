class Solution {
public:
    
    bool ispalindrome(string &s,int i,int j)
    {   
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return 0;
            }
            i++;
            j--;
        }
        

        return 1;
    }
    
    int cut (string&s , int i,int j,vector<int> &t)
    {
        int ans=INT_MAX;
        if(i>=j)
        {
            t[i]=0;
            return  0;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        if(ispalindrome(s,i,j))
        {
            t[i]=0;
            return 0;
        }
        for(int k=i;k<j;k++)
        {
            if(ispalindrome(s,i,k))
            {
            int temp=1+cut(s,k+1,j,t);
            ans=min(ans,temp);
            }
        }
        return t[i]=ans;



    }
        int minCut(string s) 
    {
        int n=s.length();
        vector<int> t(n,-1);
        return cut(s,0,n-1,t);
        
    }

};
