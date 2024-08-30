class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        for (auto it : asteroids) {
            if (st.empty() || it > 0) {
                st.push(it);
            }
            else
            {
                while (!st.empty() && abs(it) > abs(st.top()) && st.top() > 0)
                    st.pop();
                if(!st.empty() and st.top() == abs(it) && st.top()>0) {
                    st.pop();
                }
                else if(st.empty() || st.top() < 0) {
                        st.push(it);
                }
            }

        }
            vector<int> ans;
            while (!st.empty()) {
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };