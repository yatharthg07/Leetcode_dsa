class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> mp;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end() && mp[s[i]]!=t[i])
            {
                return false;
            }
            mp[s[i]]=t[i];
        }
        mp=unordered_map<char,char>();
        for(int i=0;i<n;i++)
        {
            if(mp.find(t[i])!=mp.end() && mp[t[i]]!=s[i])
            {
                return false;
            }
            mp[t[i]]=s[i];
        }
        return true;
    }
};