class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> lis(n,1);
        vector<int> lds(n,1);
        for(int i=1;i<n;i++){
            for(int k=0;k<i;k++){
                if(nums[k]<nums[i]){
                    lis[i]=max(lis[i],lis[k]+1);
                }
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int k=n-1;k>i;k--){
                if(nums[i]>nums[k]){
                    lds[i]=max(lds[i],lds[k]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            cout<<i<<" "<< lis[i]<< " "<<lds[i]<<endl; 
            if(lis[i]!=1 && lds[i]!=1)
                ans=max(ans,lds[i]+lis[i]-1);
        }
        return n-ans;
    
        
    }
};