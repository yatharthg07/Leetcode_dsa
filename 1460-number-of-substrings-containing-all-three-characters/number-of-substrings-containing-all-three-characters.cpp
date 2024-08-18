class Solution {
public:
    int numberOfSubstrings(string s) {
        long long n=s.length();
    long long l=0;
        long long r=0;
        unordered_map<long long,long long> mp1;
        long long count=0;
        long long total=n*(n+1)/2;
        long long tot1=0;
        while(r<n)
        {
            if(mp1.find(s[r])==mp1.end())
            {
                mp1[s[r]]=1;
                count++;
            }
            else
            {
                mp1[s[r]]++;
            }
            while(count>2)
            {
                if(mp1[s[l]]==1)
                {
                    mp1.erase(s[l]);
                    count--;
                }
                else
                    mp1[s[l]]--;  
                l++;      

            }
            tot1+=r-l+1;
            r++;

            
        }
        return total-tot1;
        
    }
};