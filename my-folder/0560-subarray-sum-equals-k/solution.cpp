class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> presum(n);  
        presum[0] = nums[0];

        unordered_map<int, unordered_set<int>> mp;
        mp[0].insert(-1);  
        mp[presum[0]].insert(0);

        for (int i = 1; i < n; i++) {
            presum[i] = presum[i - 1] + nums[i];
            mp[presum[i]].insert(i);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int target = presum[i] - k;
            if (mp.find(target) != mp.end()) {
                for (auto it : mp[target]) {
                    if (it < i) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};

