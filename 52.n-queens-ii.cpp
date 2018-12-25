/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (49.68%)
 * Total Accepted:    88.4K
 * Total Submissions: 177.8K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */
class Solution {
public:
    int ans; 
    int N;
    void callme(int row,  bool col[], bool dia1[], bool dia2[], vector<string> bd){
        if(row == 0){
            ans++;
            return;
        }
        for(int i=0;i<N;i++){
            if(col[i] || dia1[i+row-1] || dia2[N-1+row-1-i]) continue;
            col[i] = dia1[i+row-1] = dia2[N-1+row-1-i] = true;
            bd[row-1][i] = 'Q';
            callme(row-1, col, dia1, dia2, bd);
            bd[row-1][i] = '.';
            col[i] = dia1[i+row-1] = dia2[N-1+row-1-i] = false;
        }
    }
    int totalNQueens(int n) {
        ans = 0;
        N = n;
        bool col[n]; fill_n(col, n, false);
        bool dia1[2*n-1]; fill_n(dia1, 2*n-1, false);
        bool dia2[2*n-1]; fill_n(dia2, 2*n-1, false);
        vector<string> bd(n, string(n , '.'));
        callme(n, col, dia1, dia2, bd);
        return ans;
    }
};
