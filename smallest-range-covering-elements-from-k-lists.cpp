class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pair<int,int> p;
        int left=INT_MAX;
        int right=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            left=min(nums[i][0],left);
            right=max(nums[i][0],right);
            pq.push({nums[i][0],i,0});
        }
        p.first=left;
        p.second=right;
        int range=right-left;
        while(!pq.empty())
        {
            auto [num,i,j]=pq.top();
            pq.pop();
            j++;
            if(j==nums[i].size()) break;
            int val=nums[i][j];
            pq.push({val,i,j});
            right=max(right,val);
            left=get<0>(pq.top());
            if((right-left)<range)
            {
                range = right - left;
                p={left,right};
            }
        }
        return {p.first,p.second};
        
    }
};