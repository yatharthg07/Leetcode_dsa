class Solution {
public:
    vector<int> dir={1,0,-1,0,1};
    bool val(vector<vector<char>>& board,int i,int j,char c)
    {
        if(i<0 || i>=9 || j<0 || j>=9|| board[i][j]!='.')
        {
            return false;
        }
        for(int k=0;k<9;k++)
        {
            if(k!=i&&board[k][j]==c) return false;
            if(k!=j&&board[i][k]==c) return false;
        }
        int gridx=i/3;
        int gridy=j/3;
        for(int x=0;x<3;x++)
        {
            for(int y=0;y<3;y++)
            {
                int cordx=gridx*3+x;
                int cordy=gridy*3+y;
                if(cordx!=i && cordy!=j && board[cordx][cordy]==c)
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool rec(vector<vector<char>>& board, int i, int j)
    {

        // Find the next empty cell
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if (board[x][y] == '.') {
                    // Try all possible digits at position (x, y)
                    for (char c = '1'; c <= '9'; c++) {
                        if (val(board, x, y, c)) {
                            board[x][y] = c;
                            if (rec(board, x, y)) return true;
                            board[x][y] = '.';
                        }
                    }
                    // If no valid number is found, backtrack
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
                    rec(board,0,0);
                    return;

    }
};