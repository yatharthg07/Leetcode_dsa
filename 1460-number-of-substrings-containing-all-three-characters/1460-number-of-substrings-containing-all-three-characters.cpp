class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastseen[3]={-1,-1,-1};
        int count=0;
        int idx;
        int total=0;
        for(int i=0;i<s.size();i++)
        {
            if(lastseen[s[i]-'a']==-1)
            {
                lastseen[s[i]-'a']=i;
                count+=1;
            }
            else
            {
                lastseen[s[i]-'a']=i;
            }
            if(count==3)
            {
                idx=min({lastseen[0],lastseen[1],lastseen[2]});
                total+=idx+1;

            }

        }
        return total;
        
    }
};