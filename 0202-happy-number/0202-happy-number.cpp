class Solution {
public:
    int help(int n)
    {
        string s=to_string(n);
        int sum=0;
        for(int i=0;i<s.length();i++)
        {
            sum+=(s[i]-'0')*(s[i]-'0');
        }
        return sum;
    }
    bool isHappy(int num) {
        unordered_set<int> st;
        
        while(num!=1)
        {
            num=help(num);
            if(st.find(num)!=st.end())
            {
                return false;
            }
            st.insert(num);



        }
        return true;
        
    }
};