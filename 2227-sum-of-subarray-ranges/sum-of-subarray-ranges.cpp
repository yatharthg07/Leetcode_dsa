using ll = long long;
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }

        st = stack<int>();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }

        ll sum1 = 0;

        for (int i = 0; i < n; ++i) {
            sum1 += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i];
        }
        
        st = stack<int>();
        vector<int> l(n,-1);
        vector<int> r(n,n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                l[i] = st.top();
            }
            st.push(i);
        }

        st = stack<int>();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                r[i] = st.top();
            }
            st.push(i);
        }

        ll sum2 = 0;

        for (int i = 0; i < n; ++i) {
            sum2 += static_cast<ll>(i - l[i]) * (r[i] - i) * nums[i] ;
        }

        return sum2-sum1;



        
    }
};