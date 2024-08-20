class Solution {
public:
    string minWindow(string s, string t) {
        pair<int, int> idx;
        int l = 0, r = 0, n = s.length();
        vector<int> hash(128, 0); 
        for (char c : t) {
            hash[c]++;
        }
        int count = 0;
        int len = t.length();
        int res = INT_MAX;

        while (r < n) {
            if (hash[s[r]] > 0) {
                count++;
            }
            hash[s[r]]--;

            while (count == len) {
                if (r - l + 1 < res) {
                    res = r - l + 1;
                    idx.first = l;
                    idx.second = r;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }

        if (res != INT_MAX)
            return s.substr(idx.first, idx.second - idx.first + 1);
        else
            return "";
    }
};
