class Solution {
public:
    int largestRectangleArea(vector<int>& nums) {
        int n=nums.size();
        int nse;
        int pse;
        stack <int> st;
        int idx;
        int ans=0;

        for(int i=0;i<n;i++)
        {
            while(!st.empty()&& nums[st.top()]>=nums[i])
            {
                int idx=st.top();
                st.pop();
                nse=i;
                pse=st.empty()?-1:st.top();
                ans=max(ans,(nse-pse-1)*nums[idx]);

            } 
            st.push(i);
        }
        while(!st.empty())
        {
                int idx=st.top();
                st.pop();
                nse=n;
                pse=st.empty()?-1:st.top();
                ans=max(ans,(nse-pse-1)*nums[idx]);

        }

        return ans;
        
    }
};