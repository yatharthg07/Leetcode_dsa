class Solution {
public:
    string minWindow(string s, string t) {
        pair<int,int> idx;
        int l=0;int r=0;int n=s.length();
        unordered_map<char,int> mp;
        for(auto c:t)
        {
            mp[c]++;
        }
        int count=0;
        int len=t.length();
        int res=INT_MAX;
        while(r<n)
        {   
            if(mp.find(s[r])!=mp.end()){
            if(mp[s[r]]>0)
                count++;
            mp[s[r]]--;
            }
            while(count==len)
            {
                if(r-l+1<res)
                {
                    res=r-l+1;
                    idx.first=l;
                    idx.second=r;
                }
                if(mp.find(s[l])!=mp.end()){
                    mp[s[l]]++;
                    if(mp[s[l]]>0)
                    {
                        count--;
                    }
                }
                l++;
            }
            r++;


        }
        if(res!=INT_MAX)
        return s.substr(idx.first,idx.second-idx.first+1);
        else
            return "";

        
    }
};