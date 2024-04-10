class Solution {
public:
bool isPalindrome(string S)
{
    for (int i = 0; i < S.length() / 2; i++) {
 
        if (S[i] != S[S.length() - i - 1]) {
            // Return No
            return false;
        }
    }
    // Return "Yes"
    return true;
}

    vector<vector<string>> ans;
    void rec(string &s , vector<string> &curr, int pos)
    {
        if(pos==s.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int i=pos;i<s.size();i++)
        {
            string temp=s.substr(pos,i-pos+1);
            if(isPalindrome(temp))
            {
                curr.push_back(temp);
                rec(s,curr,i+1);
                curr.pop_back();
                
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector <string> curr;
        rec(s,curr,0);
        return ans;
        
    }
};
