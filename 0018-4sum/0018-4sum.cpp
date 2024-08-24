#define ll long long

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, ll sum) {
        int n=nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for (int j = 0; j < n; j++) {
            if (j && nums[j] == nums[j - 1]) {
                    continue;
            }
            for (int i = j+1; i < n; i++) {
                if (i!=j+1 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int l = i + 1;
                int r = n - 1;
                ll target = sum-nums[i]-nums[j];
                while (l < r) {
                    if (nums[l] == nums[l - 1] && l != i + 1) {
                        l++;
                    } else if (r != n - 1 && nums[r] == nums[r + 1]) {
                        r--;
                    } else if (nums[l] + nums[r] < target) {
                        l++;
                    } else if (nums[l] + nums[r] > target) {
                        r--;
                    } else {
                        ans.push_back({nums[l], nums[r], nums[i],nums[j]});
                        l++;
                        r--;
                    }
                }
            }
        }
        return ans;
    }
};