class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        char maxc=s[0];
        unordered_map<char,int> mp;
        int ans=0;
        int l=0;
        int r=0;
        while(r<n)
        {
            if(mp.find(s[r])==mp.end())
            {
                mp[s[r]]=1;
            }
            else{
                mp[s[r]]++;
                if(mp[s[r]]>mp[maxc])
                {
                    maxc=s[r];
                }
            }
            if(mp[maxc]+k<r-l+1)
            {
                mp[s[l]]--;
                l++;

            }
            if(mp[maxc]+k>=r-l+1)
            {
                ans=max(r-l+1,ans);

            }
            r++;

        }
        return ans;

        
    }
};