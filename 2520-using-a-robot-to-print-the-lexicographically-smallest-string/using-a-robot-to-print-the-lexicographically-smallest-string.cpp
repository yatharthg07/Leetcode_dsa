class Solution {
public:
    string robotWithString(string s) {
        map<char, int> mp;
        stack<char> st;
        for (auto c : s) {
            mp[c]++;
        }
        string ans;
        for (int i = 0; i < s.length(); i++) {
            st.push(s[i]);
            mp[s[i]]--;
            if (mp[s[i]] == 0) {
                mp.erase(s[i]);
            }
            while (!st.empty()) {
                auto it = mp.lower_bound(st.top());
                if (it == mp.begin()) {
                    ans.push_back(st.top());
                    st.pop();
                } else {
                    break;
                }
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};