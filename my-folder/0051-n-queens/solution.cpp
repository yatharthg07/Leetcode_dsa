class Solution {
public:
    vector<vector<string>> ans;
bool isvalid(vector<string> &board, int row, int col, int n) {
        for (int i = 0; i < col; ++i) {
            if (board[row][i] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row + 1, j = col - 1; i < n && j >= 0; ++i, --j) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
    void rec(vector<string> &board,int row,int col,int size)
    {
        board[row][col]='Q';
        if(col==size-1)
        {
            ans.push_back(board);         
        }
        
        for(int i=0;i<size;i++)
            {

                if(isvalid(board,i,col+1,size))
                {
                        rec(board,i,col+1,size);
                }
            }
        
        board[row][col]='.';
    }
    vector<vector<string>> solveNQueens(int n) {
        for(int i=0;i<n;i++)
        {
                vector<string> board(n,string(n,'.'));
                rec(board,i,0,n);


        }
        return ans;

        
        
    }
};
