class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++)
        {
            gas[i]-=cost[i];
        }
        int sum=accumulate(gas.begin(),gas.end(),0);
        if(sum<0)
        {
            return -1;
        }
        int idx=0;
        sum=0;
        for(int i=0;i<2*n;i++)
        {
            if(sum<0)
            {
                sum=0;
                idx=i%n;
            }
            sum+=gas[i%n];


        }
        return idx;
        
    }
};