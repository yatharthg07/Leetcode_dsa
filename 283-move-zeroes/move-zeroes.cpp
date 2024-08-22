class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeros = 0; 
        for (int i=0;i<nums.size();i++){
	        if (nums[i]==0){
                zeros++; 
            }
            else if (zeros > 0) {
	            int t = nums[i];
	            nums[i]=0;
	            nums[i-zeros]=t;
            }
        }
    }
    
};