/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * https://leetcode.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (23.24%)
 * Likes:    798
 * Dislikes: 440
 * Total Accepted:    150.5K
 * Total Submissions: 647.5K
 * Testcase Example:  '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * Given a 2D board containing 'X' and 'O' (the letter O), capture all regions
 * surrounded by 'X'.
 * 
 * A region is captured by flipping all 'O's into 'X's in that surrounded
 * region.
 * 
 * Example:
 * 
 * 
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 * 
 * 
 * After running your function, the board should be:
 * 
 * 
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 * 
 * 
 * Explanation:
 * 
 * Surrounded regions shouldn’t be on the border, which means that any 'O' on
 * the border of the board are not flipped to 'X'. Any 'O' that is not on the
 * border and it is not connected to an 'O' on the border will be flipped to
 * 'X'. Two cells are connected if they are adjacent cells connected
 * horizontally or vertically.
 * 
 */
class Solution {
public:
    void callme(vector<vector<char>>& board, int i, int j, const char &c, const char &with){
        int n = board.size();
        int m = board[0].size();
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=c)
            return;
        board[i][j] = with;
        callme(board, i+1, j, c, with);
        callme(board, i, j+1, c, with);
        callme(board, i-1, j, c, with);
        callme(board, i, j-1, c, with);
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if(n == 0)  return;
        int m = board[0].size();
        
        for(int i=0; i<n; i++){
            if(board[i][0]=='O')
                callme(board, i, 0, 'O', '.');
            if(board[i][m-1]=='O')
                callme(board, i, m-1, 'O', '.');
        }
        for(int j=1; j<m-1; j++){
            if(board[0][j] == 'O')
                callme(board, 0, j, 'O', '.');
            if(board[n-1][j]=='O')
                callme(board, n-1, j, 'O', '.');
        }
        for(int i=0; i<n;i++)
            for(int j=0; j<m;j++)
                if(board[i][j] == 'O')
                    callme(board, i, j, 'O', 'X');
        
        for(int i=0; i<n;i++)
            for(int j=0; j<m;j++)
                if(board[i][j] == '.')
                    callme(board, i, j, '.', 'O');

    }
};

