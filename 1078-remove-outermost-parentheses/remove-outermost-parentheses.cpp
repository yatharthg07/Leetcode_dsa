class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int cnt=0;
        int idx=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                cnt++;
            else
                cnt--;
            if(cnt==0)
            {
                ans+=s.substr(idx+1,i-idx-1);
                idx=i+1;
            }
        }
        return ans;
    }
};