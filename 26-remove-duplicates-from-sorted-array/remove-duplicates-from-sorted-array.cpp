class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end()) ;
        int k=st.size();
        nums.clear();
        nums.assign(st.begin(),st.end());
        return k;
        
    }
};