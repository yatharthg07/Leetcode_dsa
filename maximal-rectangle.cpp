class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int nse;
        int pse;
        stack<int> st;
        int idx;
        int ans = 0;
        vector<int> nums(col);

        for (int i = 0; i < row; i++) {
            st=stack<int> ();

            for(int j=0;j<col;j++)
            {
                if(i==0)
                {
                    nums[j]=matrix[i][j]=='0'?0:1;

                }
                else{
                    nums[j]=matrix[i][j]=='0'?0:++nums[j];
                }
            }
            for (int j = 0; j < col; j++) {
                while (!st.empty() && nums[st.top()] >= nums[j]) {
                    int idx = st.top();
                    st.pop();
                    nse = j;
                    pse = st.empty() ? -1 : st.top();
                    ans = max(ans, (nse - pse - 1) * nums[idx]);
                }
                st.push(j);
            }
            while (!st.empty()) {
                int idx = st.top();
                st.pop();
                nse = col;
                pse = st.empty() ? -1 : st.top();
                ans = max(ans, (nse - pse - 1) * nums[idx]);
            }
        }
        return ans;
    }
};