class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        if(intervals.empty())
        {
            ans.push_back(newInterval);
            return ans;
        }
        int flag=0;
        if(!flag && newInterval[0]<=intervals[0][0])
            {
                    ans.push_back(newInterval);
                    flag=1;
            }     
        for(auto it:intervals)
        {
            if(ans.empty())
            {
                ans.push_back(it);
                continue;
            }
            if(!flag && newInterval[0]<=it[0])
            {
                if(newInterval[0]<=ans.back()[1])
                {
                    ans.back()[1]=max(ans.back()[1],newInterval[1]);
                    flag=1;
                }
                else
                {
                    ans.push_back(newInterval);
                    flag=1;
                }
            }       
            if(it[0]<=ans.back()[1])
            {
                ans.back()[1]=max(ans.back()[1],it[1]);
            }
            else
            {
                ans.push_back(it);
            }

        }
        if(!flag)
            {
                if(newInterval[0]<=ans.back()[1])
                {
                    ans.back()[1]=max(ans.back()[1],newInterval[1]);
                    flag=1;
                }
                else
                {
                    ans.push_back(newInterval);
                }
            }  
    
        return ans;
        
    }
};