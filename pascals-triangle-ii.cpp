class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int rowno=rowIndex+1;
        ans.push_back(1);
        long long temp=1;
        for(int i=1;i<rowno;i++)
        {
            temp*=(rowno-i);
            temp/=(i);
            ans.push_back(temp);
        }
        return ans;
        
    }
};