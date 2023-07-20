class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())
        {
            return false;
        }
        vector<int> a(26,0);
        for(int i=0;i<s.length();i++)
        {
            a[s[i]-97]++;
            a[t[i]-97]--;
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]!=0)
            {
                return false;
            }
        }
        return true;


        
    }
};
