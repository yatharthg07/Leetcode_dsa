class Solution {
public:
    bool ispal(string &s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return s;
        int idx;
        for(int i=n-1;i>=0;i--)
        {
            idx=i;
            if(s[i]==s[0] && ispal(s,0,i))
            {
                break;
            }
        }
        if(idx==n-1)
        {
            return s;
        }
        string temp=s.substr(idx+1);
        reverse(temp.begin(),temp.end());
        return temp+s;
    }
};
