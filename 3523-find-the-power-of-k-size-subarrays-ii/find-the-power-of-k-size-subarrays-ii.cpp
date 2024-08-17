class Solution {
public:
    vector<int> res;
    pair<int,int> check(vector<int>& nums, int i, int k) {
        int idx=-1;

        for(int j = i; j < i + k - 1; j++) {
            if(nums[j] + 1 != nums[j + 1]) {
                idx=j;
                break;
            }
        }
        if(idx==-1)
        {
            res.push_back(nums[i+k-1]);
            return {i+1,1};
        }
        else
        {
            for(int j=i;j<=idx && j+k-1<nums.size();j++)
            {
                res.push_back(-1);
            }
            idx++;
            return {idx,0};

        }
    }
    vector<int> resultsArray(vector<int>& nums, int k) {

        if(k==1)
        {
            return nums;
        }
        int last;
        int n=nums.size();
        int i=0;
        int flag=0;
        while(i<n-k+1)
        {
            if(flag==0){
                auto [idx,val]=check(nums,i,k);
                if(val)
                {
                    flag=1;
                    i=idx;


                }
                else
                {
                    i=idx;
                }
            }
            else if(flag)
            {
                if(nums[i+k-2]+1==nums[i+k-1])
                {
                    res.push_back(nums[i+k-1]);
                    i++;
                }
                else
                {
                    flag=0;
                    res.push_back(-1);
                    i++;
                }
            }

        }
        return res;
        
    }
};