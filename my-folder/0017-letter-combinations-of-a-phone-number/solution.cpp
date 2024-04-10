class Solution {
public:
    vector<string> ans;
    void rec(string &digits,map<int,string> &keypad,int pos,string &cur)
    {
        if(cur.length()==digits.length())
        {
            ans.push_back(cur);
            return;
        }
        for(auto i:keypad[digits[pos]-'0'])
        {
            cur.push_back(i);
            rec(digits,keypad,pos+1,cur);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

    if(digits.size()==0)
    {
        return {};
    }
        map<int, string> keypad = {
    {2, "abc"},
    {3, "def"},
    {4, "ghi"},
    {5, "jkl"},
    {6, "mno"},
    {7, "pqrs"},
    {8, "tuv"},
    {9, "wxyz"}};
    
    string curr;
    rec(digits,keypad,0,curr);
    return ans;
    }
};
