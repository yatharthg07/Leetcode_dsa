class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int l=0;
        int r=0;
        int len=0;
        while(r<s.length())
        {
            if(set.find(s[r])==set.end())
            {
                set.insert(s[r]);
            }
            else
            {
                set.erase(s[l]);
                l++;
                
                continue;
            }
            len=max(len,r-l+1);
            r++;

        }
        return len;
    }
};