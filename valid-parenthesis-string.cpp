class Solution {
public:
    bool checkValidString(string s) {
        int min=0;
        int max=0;
        for(auto it:s)
        {
            if(it=='(')
            {
                max++;
                min++;
            }
            else if(it==')')
            {
                max--;
                min--;
            }
            else
            {
                
                max++;
                min--;
            }
            if(max<0)
            {
                return false;
            }
            if(min<0)
            {
                min=0;
            }
        }
        if(min==0)
        {
            return true;
        }
        return false;


        
    }
};