class Solution {
public:
    int check(vector<int>& nums, int i, int k) {
        for(int j = i; j < i + k - 1; j++) {
            if(nums[j] + 1 != nums[j + 1]) {
                return -1;
            }
        }
        return nums[i + k - 1];
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> res;
        if(k==1)
        {
            return nums;
        }
        int flag=0;
        int last;
        int n=nums.size();
        for(int i=0;i<n-k+1;i++)
        {
            if(flag==1)
            {
                if(nums[i+k-1]==last+1)
                {
                    
                    last=nums[i+k-1];
                    res.push_back(last);
                    
                    continue;
                }
                else{
                    flag=0;
                    res.push_back(-1);
                    continue;


                
                }
            }
            if(flag==0){
                last=check(nums,i,k);
            }
            if(last!=-1)
            {
                flag=1;
                res.push_back(last);
            }
            else
            {
                flag=0;
                res.push_back(-1);

            }
        }
        return res;
        
    }
};
