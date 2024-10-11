#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& v, int m) {
        int n = v.size();
        int even=0;
        if (m % 2 == 0) {
            even = 1;
        }
        vector<double> ans;
        ordered_set<ll> s;

        for (int i = 0; i < m; i++) {
            s.insert(v[i]);
        }
        if (even) {
            ans.push_back(
                (*s.find_by_order(m / 2) + *s.find_by_order(m / 2 - 1)) / 2.0);
        } else {
            ans.push_back(*s.find_by_order(m / 2));
        }
        for (int i = m; i < n; i++) {
            s.erase(s.upper_bound(v[i - m]));
            s.insert(v[i]);
            if (even) {
                ans.push_back(
                    (*s.find_by_order(m / 2) + *s.find_by_order(m / 2 - 1)) /
                    2.0);
            } else {
                ans.push_back(*s.find_by_order(m / 2));
            }
        }
        return ans;
    }
};