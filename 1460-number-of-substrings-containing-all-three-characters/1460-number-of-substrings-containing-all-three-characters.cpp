class Solution {
public:
    int plzhelp(string s, int k) {
    
        int i = 0;
        int j = 0;
        unordered_map<char, int> mp;
        int count = 0;

        while (j < s.length()) {
            mp[s[j]]++;

            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }

            count += (j - i + 1);
            j++;
        }
        return count;
    }

    int numberOfSubstrings(string s) {
        int k = 3;
        int count = plzhelp(s, k) - plzhelp(s, k - 1);
        return count;
    }
};