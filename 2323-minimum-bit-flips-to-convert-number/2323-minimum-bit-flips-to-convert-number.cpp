class Solution {
public:
    int minBitFlips(int start, int goal) {
        int x=start^goal;
        int cnt=0;
        for(int i=1;i<=x;i<<=1)
        {
            if((i&x)!=0)
            {
                cnt++;
            }
        }
        return cnt;
        
    }
};