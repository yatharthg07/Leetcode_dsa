class Solution {
public:
    vector<string> ans;
    void rec(string res,int n,int open,int close)
    {
        if(open==n)
        {
            while(open-close>0)
            {
                res.push_back(')');
                close++;
            }
            ans.push_back(res);
            return ;
        }
        res.push_back('(');
        rec(res,n,open+1,close);
        res.pop_back();
        if(open-close)
        {
            res.push_back(')');
            rec(res,n,open,close+1);
            res.pop_back();
        }

    }

    vector<string> generateParenthesis(int n) {
        string res;
        rec(res,n,0,0);
        return ans;
    }
};