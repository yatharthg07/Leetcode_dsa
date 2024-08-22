class Solution {
public:
    void moveZeroes(vector<int>& nums) {

            int l=-1;
            int r=-1;
            int n=nums.size();
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    l=i;
                    break;

                }

            }
            if(l==-1)
            {
                return;
            }
            for(int i=l+1;i<n;i++)
            {
                if(nums[i]!=0)
                {
                    r=i;
                    break;
                }
            }
            if(r==-1)
            {
                return;
            }
            for(int i=r;i<n;i++)
            {
                if(nums[i]!=0)
                {
                    swap(nums[l],nums[i]);
                    l++;

                }
            }

        
    }
};