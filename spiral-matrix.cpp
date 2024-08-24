class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int tot = n * m;
        n--;
        m--;
        int l = 0;
        int t = 0;
        int i = 0;
        int j = 0;
        vector<int> ans;
        int cnt = 0;
        while (cnt < tot) {
            if (i == t && j == l) {
                while (j <= m) {
                    ans.push_back(nums[i][j]);
                    j++;
                    cnt++;
                }
                t++;
                i++;
                j--;
            } else if (i == t && j == m) {
                while (i <= n) {
                    ans.push_back(nums[i][j]);
                    i++;
                    cnt++;
                }
                m--;
                j--;
                i--;
            } else if (i == n && j == m) {
                while (j >= l) {
                    ans.push_back(nums[i][j]);
                    j--;
                    cnt++;
                }
                n--;
                i--;
                j++;
            } else if (i == n && j == l) {
                while (i >= t) {
                    ans.push_back(nums[i][j]);
                    i--;
                    cnt++;
                }
                l++;
                j++;
                i++;
            }
        }
        return ans;
    }
};