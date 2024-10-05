class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.length();
        unordered_map<char, int> mp;
        
        for (auto c : s1) {
            mp[c]++;
        }

        int l = 0, r = 0;

        while (r < n && l < n) {
            if (mp.find(s2[r]) != mp.end()) {
                mp[s2[r]]--;
            }
            if (mp.find(s2[r]) == mp.end()) {
                for (int i = l; i <= r; i++) {
                    if (mp.find(s2[i]) != mp.end()) {
                        mp[s2[i]]++;
                    }
                }
                l = r + 1;
            }
            else if (mp[s2[r]] < 0) {
                while (l < n && mp[s2[r]] < 0) {
                    if (mp.find(s2[l]) != mp.end()) {
                        mp[s2[l]]++;
                    }
                    l++;
                }
            }
            if (r - l + 1 == s1.length()) {
                return true;
            }

            r++;
        }

        return false;
    }
};
