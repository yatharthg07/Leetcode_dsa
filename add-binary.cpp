class Solution {
public:
    string addBinary(string a, string b) {
        int n1=a.length();
        int n2=b.length();
        int x=0;
        int y=0;
        for(int i=0;i<n1;i++)
        {
            if(a[n1-i-1]=='1')
            {
                x+=pow(2,i);
            }
        }
        for(int i=0;i<n2;i++)
        {
            if(b[n2-i-1]=='1')
            {
                y+=pow(2,i);
            }
        }

        int sum=x+y;
        string s;
        if(sum==0)
        {
            return "0";
        }
        while(sum>0)
        {
            if(sum%2==1)
            {
                s.push_back('1');
            }
            else
            {
                s.push_back('0');
                
            }
            sum=sum/2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};