class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.length();
        int m=needle.length();
        vector<int> lps(m,0);
        int length=0;
        int i=1;
        int j=0;
        while(i<m)
        {
            if(needle[i]==needle[length])
            {
                length++;
                lps[i]=length;
                i++;
            }
            else
            {
                if(length!=0)
                {
                    length=lps[length-1];
                }
                else
                {
                    length=0;
                    lps[i]=0;
                    i++;
                }
            }
        }
        i=0;
        j=0;
        while(i<n && j<m)
        {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j!=0)
                    j=lps[j-1];
                else
                    i++;    
            }
        }
        if(j==m)
        {
            return i-j;
        }
        else
        {
            return -1;
        }
        
    }
};