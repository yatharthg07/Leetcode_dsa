#define ll unsigned long long int
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        vector<ll> prev(m+1, 0);
        vector<ll> curr(m+1, 0);

        prev[0] = 1;
        curr[0]= 1;

        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    curr[j] = prev[j] + prev[j - 1]; 
                } else {
                    curr[j] = prev[j]; 
                }
            }
            prev = curr;
        }

        return prev[m]; // The result is stored in prev[m]
    }
};
