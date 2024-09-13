class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int res = 1;
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.length() < b.length();
        });
        unordered_map<string, int> st;
        for (auto it : words) {
            st[it] = 1;
        }
        int n = words.size();
        string temp;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < words[i].length(); j++) {
                temp = words[i].substr(0, j) + words[i].substr(j + 1);
                if (st.find(temp) != st.end()) {
                    if (st[words[i]] < st[temp] + 1) {
                        st[words[i]] = st[temp] + 1;
                    }
                }
            }
            res = max(res, st[words[i]]);
        }
        return res;
    }
};