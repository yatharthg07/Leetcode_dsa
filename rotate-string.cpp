class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        if(goal.length()!=n)
        {
            return false;
        }
        if((goal+goal).find(s)!=string::npos)
        {
            return true;
        }
        return false;
        // int n=s.length();
        // if(goal.length()!=n)
        // {
        //     return false;
        // }
        // auto idx=goal.find(s[0]);
        // if(idx==string::npos)
        // {
        //     return false;
        // }
        // for(int i=0;i<n;i++)
        // {
        //     if(s[i]!=goal[(i+idx)%n])
        //     {
        //         return false;
        //     }
        // }
        // return true;

    }
};