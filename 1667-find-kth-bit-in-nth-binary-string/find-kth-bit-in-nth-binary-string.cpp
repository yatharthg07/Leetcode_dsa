class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1) return '0';
        int len=pow(2,n)-1;
        int mid=(len+1)/2;
        if(mid==k) return '1';
        else if(k<mid) return findKthBit(n-1,k);
        else {
            int newpos=k-mid;
            char ans=findKthBit(n-1,mid-newpos);
            return ans=='1'?'0':'1';
        }
    }
};