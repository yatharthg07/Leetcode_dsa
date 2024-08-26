class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
     stack<int> st;
 
     int n=nums.size();
     vector<int> ans(n);

     for(int i=n-1;i>=0;i--)
     {
        while(!st.empty() && nums[i]>=st.top())
        {
            st.pop();
        }        
        if(!st.empty())
        {
            ans[i]=st.top();
        }
        else
        {
            ans[i]=INT_MIN;
        }
        st.push(nums[i]);
     }
     for(int i=n-1;i>=0;i--)
     {
        if(st.empty())
        {
            break;
        }
        if(ans[i]!=INT_MIN)
        {
            continue;
        }
        while(!st.empty() && nums[i]>=st.top())
        {
            st.pop();
        }        
        if(!st.empty())
        {
            ans[i]=st.top();
        }
        else
        {
            ans[i]=INT_MIN;
        }
     }
     for(auto &it :ans)
     {
        if(it==INT_MIN)
        {
            it=-1;
        }
     }
        
        return ans;
    }
};