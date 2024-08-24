class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int ele1;
        int ele2;
        int cnt1=0;
        int cnt2=0;
        for(auto it:nums)
        {
            if(cnt1==0)
            {
                ele1=it;
                cnt1++;                
            }
            else if(cnt2==0 && cnt1!=0 && ele1!=it)
            {
                ele2=it;
                cnt2++;
            }
            else if(it==ele1)
            {
                cnt1++;
            }
            else if(it==ele2)
            {
                cnt2++;
            }
            else
            {
                if(cnt1<cnt2)
                {
                    cnt1--;
                }
                else
                {
                    cnt2--;
                }
            }
        }

        cnt1=0;
        cnt2=0;
        for(auto it:nums)
        {
            if(it==ele1)
            {
                cnt1++;
            }
            else if(it==ele2){
                cnt2++;

            }
        }
        vector<int> ans;
        if(cnt1>n/3)
        {
            ans.push_back(ele1);
        }
        if(cnt2>n/3){
            ans.push_back(ele2);
        }
        return ans;
        
    }
};