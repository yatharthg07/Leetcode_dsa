class Solution {
public:
    static bool cmp(const int &a, const int &b) {
        string x = to_string(a);
        string y = to_string(b);
        return x + y > y + x;  
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);

        string s;
        for(auto it:nums)
        {
            s+=to_string(it);
        }
        if(s[0]=='0') return "0";
        return s;
        
    }
};