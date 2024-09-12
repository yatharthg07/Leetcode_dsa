class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(auto c:allowed)
        {
            st.insert(c);
        }
        int cnt=0;
        for(auto s:words)
        {
            for(auto c:s)
            {
                if(st.find(c)==st.end())
                {
                    cnt--;
                    break;
                }
            }
            cnt++;
        }
        return cnt;

        
    }
};