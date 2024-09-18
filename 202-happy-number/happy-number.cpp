class Solution {
public:
    int help(int n) {
        int sum = 0, tmp;
        while (n) {
            tmp = n % 10;
            sum += tmp * tmp;
            n /= 10;
        }
        return sum;
    }
    bool isHappy(int num) {
        unordered_set<int> st;

        while (num != 1) {
            num = help(num);
            if (st.find(num) != st.end()) {
                return false;
            }
            st.insert(num);
        }
        return true;
    }
};