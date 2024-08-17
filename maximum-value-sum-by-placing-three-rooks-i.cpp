class Solution {
public:
    struct State {
        int row;
        int count;
        vector<bool> usedCols;

        // Custom comparison operator for using State as a key in map
        bool operator<(const State& other) const {
            if (row != other.row) return row < other.row;
            if (count != other.count) return count < other.count;
            return usedCols < other.usedCols;
        }
    };

    long long maxSum = LLONG_MIN;
    map<State, long long> memo;

    long long placeRooks(vector<vector<int>>& board, int row, vector<bool>& usedCols, long long currentSum, int count) {
        int m = board.size();
        int n = board[0].size();
        
        if (count == 3) {
            return currentSum;
        }

        if (row >= m) return LLONG_MIN;

        // Create a memoization key based on the current state
        State key = {row, count, usedCols};
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        long long maxLocalSum = LLONG_MIN;

        // Try placing a rook in each column
        for (int col = 0; col < n; col++) {
            if (!usedCols[col]) {
                usedCols[col] = true;
                maxLocalSum = max(maxLocalSum, placeRooks(board, row + 1, usedCols, currentSum + board[row][col], count + 1));
                usedCols[col] = false;
            }
        }
        
        // Also explore the option of not placing a rook in the current row
        maxLocalSum = max(maxLocalSum, placeRooks(board, row + 1, usedCols, currentSum, count));
        
        // Store the result in the memo table
        memo[key] = maxLocalSum;
        return maxLocalSum;
    }

    long long maximumValueSum(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<bool> usedCols(n, false);
        
        return placeRooks(board, 0, usedCols, 0, 0);
    }
};
