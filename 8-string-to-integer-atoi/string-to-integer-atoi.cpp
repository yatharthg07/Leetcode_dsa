class Solution {
public:
    int myAtoi(string s) {
        int INT_MAX_DIV10 = INT_MAX / 10; 
        int ans=0;
        int n=s.length();
        int i=0;
        int neg=1;
        while(s[i]==' ') i++;
        if(s[i]=='-') {
            neg=-1;
            i++;
        }
        else if(s[i]=='+') i++;
        while(s[i]=='0') i++;

        while(i<n)
        {
            if(!isdigit(s[i]))
            {
                break;
            }
            int digit = s[i] - '0';

            if (ans > INT_MAX_DIV10 || (ans == INT_MAX_DIV10 && digit > 7)) {
                return neg == 1 ? INT_MAX : INT_MIN;
            }
            
            ans = ans * 10 + digit;
            i++;
        }
        if(neg*ans<INT_MIN)
        {
            return INT_MIN;
        }
        else if(neg*ans>INT_MAX)
        {
            return INT_MAX;
        }
        return neg*ans;

        
    }
};