class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     stack<int> st;
     st.push(INT_MIN);
     unordered_map<int,int> mp;
     int n2=nums2.size();
     for(int i=n2-1;i>=0;i--)
     {
        while(!st.empty() && nums2[i]>st.top())
        {
            st.pop();
        }        
        if(!st.empty())
        {
            mp[nums2[i]]=st.top();
        }
        else
        {
            mp[nums2[i]]=-1;
        }
        st.push(nums2[i]);
     }
     vector<int> ans;
     for(auto it:nums1)
     {
        ans.push_back(mp[it]);

     }
     return ans;
        
        
    }
};