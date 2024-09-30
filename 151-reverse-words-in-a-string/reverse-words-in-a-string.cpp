class Solution {
public:
    string reverseWords(string s) {
        stringstream st(s);

        string ans;
        string word;
        while(st>>word)
        {
            ans=word+ans;
            ans=" "+ans;
        }
        return ans.substr(1);
        
    }
};