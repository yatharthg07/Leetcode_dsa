class Solution {
public:
int cnt=0;
    void solve(vector<int>&nums,int i,int val,int cur)
    {
        if(i==nums.size()){
            if(cur==val){
                cnt++;
            }
            return;
        }
        solve(nums,i+1,val,cur);
        solve(nums,i+1,val,cur|nums[i]);
        
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int val=0;
        for(auto it:nums){
            val|=it;
        }
        solve(nums,0,val,0);
        return cnt;

        
    }
};