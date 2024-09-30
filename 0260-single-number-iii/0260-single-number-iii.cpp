#define ll long long
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        ll xorr=0;
        for(auto it:nums)
        {
            xorr^=it;
        }
        ll diff=xorr&(-xorr);
        ll b1=0;
        ll b2=0;
        for(auto it:nums)
        {
            if((diff&it))
            {
                b1^=it;
            }
            else b2^=it;
        }
        return {int(b1),int(b2)};
        
    }
};