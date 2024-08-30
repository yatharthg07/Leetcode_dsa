class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for(auto it:asteroids)
        {
            if(st.empty())
            {
                st.push(it);
                continue;
            }
            
            if(it<0 && st.top()>0)
            {
                if(abs(it)>abs(st.top()))
                {
                    while(!st.empty() && abs(it)>abs(st.top()) && st.top()>0 ) st.pop();

                    if(st.empty())
                    {
                        st.push(it);
                    }
                    else if(abs(st.top())==abs(it) && st.top()>0)
                    {
                        st.pop();
                    }
                    else if(st.top()<0)
                    {
                        st.push(it);
                    }

                    
                }
                else if(abs(it)==abs(st.top()))
                { 
                    st.pop();

                }
                
            }
            else{
                st.push(it);
            }

        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};