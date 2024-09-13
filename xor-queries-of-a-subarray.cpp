class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int> prexor(n+1);
        vector<int> postxor(n+1);
        prexor[0]=0;
        for(int i=1; i<=n;i++)
        {
            prexor[i]=arr[i-1]^prexor[i-1];
        }
        int xorr=prexor[n];
        postxor[n]=0;
        for(int i=n-1; i>=0;i--)
        {
            postxor[i]=arr[i]^postxor[i+1];
        }
        vector<int> ans;
        int temp;
        for(auto it:queries)
        {
            ans.push_back(xorr^prexor[it[0]]^postxor[it[1]+1]);
        }
        return ans;

        
    }
};