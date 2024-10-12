class Solution {
public:
    static bool cmp(vector<int> a,vector<int> b)
    {
        return a[1]<b[1];
    }
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt=0;
        multiset<int> st;
        for(auto it:intervals)
        {
            if(st.empty())
            {
                cnt++;
                st.insert(it[1]);
                continue;
            }
            auto ite=st.lower_bound(it[0]);
            if(ite==st.begin())
            {
                cnt++;
                st.insert(it[1]);
            }
            else{
                ite--;
                st.erase(ite);
                st.insert(it[1]);
            }
        }
        return cnt;
        
    }
};