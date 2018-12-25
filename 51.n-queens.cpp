/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (36.52%)
 * Total Accepted:    121.3K
 * Total Submissions: 331.9K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */
class Solution {
public:
    vector<vector<string>> vec;
    void callme(int row, vector<string> bd, int n, bool dia1[], bool dia2[]){
        if(row == -1){
            vec.push_back(bd);
            return;
        }

        for(int i=0;i<n;i++){
            if(dia1[i+row] || dia2[n-1+i-row] || count(bd[i].begin(), bd[i].end(), 'Q') > 0)  continue;
            bd[i][row] = 'Q';
            dia1[i+row] = true;
            dia2[n-1+i-row] = true;
            callme(row-1, bd, n, dia1, dia2);
            bd[i][row] = '.';
            dia1[i+row] = false;
            dia2[n-1+i-row] = false;
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        // if( n < 2)  return {};
        string temp(n, '.');
        vector<string> board;
        for(int i=0;i<n;i++)    board.push_back(temp);
        bool dia1[2*n-1]; fill_n(dia1, 2*n-1, false);
        bool dia2[2*n-1]; fill_n(dia2, 2*n-1, false);
        callme(n-1, board, n, dia1, dia2);
        return vec;
    }
};
