/*
 * @lc app=leetcode id=1020 lang=cpp
 *
 * [1020] Number of Enclaves
 *
 * https://leetcode.com/problems/number-of-enclaves/description/
 *
 * algorithms
 * Medium (54.69%)
 * Total Accepted:    8.5K
 * Total Submissions: 15.5K
 * Testcase Example:  '[[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]'
 *
 * Given a 2D array A, each cell is 0 (representing sea) or 1 (representing
 * land)
 * 
 * A move consists of walking from one land square 4-directionally to another
 * land square, or off the boundary of the grid.
 * 
 * Return the number of land squares in the grid for which we cannot walk off
 * the boundary of the grid in any number of moves.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
 * Output: 3
 * Explanation: 
 * There are three 1s that are enclosed by 0s, and one 1 that isn't enclosed
 * because its on the boundary.
 * 
 * Example 2:
 * 
 * 
 * Input: [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
 * Output: 0
 * Explanation: 
 * All 1s are either on the boundary or can reach the boundary.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 500
 * 1 <= A[i].length <= 500
 * 0 <= A[i][j] <= 1
 * All rows have the same size.
 * 
 */
class Solution {
public:
    void callme(int i, int j, vector<vector<int>> &A, int &n, int &m){
        if(i<0 || j<0 || i >= n || j>=m || A[i][j] == 0)
            return;
        A[i][j] = 0;
        callme(i+1, j, A, n, m);
        callme(i, j+1, A, n, m);
        callme(i-1, j, A, n, m);
        callme(i, j-1, A, n, m);
    } 
    int numEnclaves(vector<vector<int>>& A) {
        int n = A.size();
        int m = A[0].size();
        for(int i=0; i<n; i++)
            callme(i, 0, A, n, m), callme(i, m-1, A, n, m);
        for(int j=0; j<m; j++)
            callme(0, j, A, n, m), callme(n-1, j, A, n, m);

        int ans = 0;
    
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                ans += A[i][j];
        return ans;
    }
};
