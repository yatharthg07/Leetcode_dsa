class Solution {
public:
    int subarraysDivByK(vector<int>& a, int k) {
        int n=a.size();
        vector<int> pref(n, 0);
        int sum = (a[0] % k + k) % k;
        pref[0] = sum;
        for (int i = 1; i < n; i++) {
            sum += a[i];
            pref[i] = (sum % k + k) % k;
        }
        map<int, int> mp;
        mp[0] = 1;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += mp[pref[i]];
            mp[pref[i]]++;
        }
        return ans;
    }
};