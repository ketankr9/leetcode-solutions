/*
 * @lc app=leetcode id=741 lang=cpp
 *
 * [741] Cherry Pickup
 *
 * https://leetcode.com/problems/cherry-pickup/description/
 *
 * algorithms
 * Hard (30.25%)
 * Total Accepted:    10.8K
 * Total Submissions: 35.7K
 * Testcase Example:  '[[0,1,-1],[1,0,-1],[1,1,1]]'
 *
 * In a N x N grid representing a field of cherries, each cell is one of three
 * possible integers.
 * 
 * 
 * 
 * 
 * 0 means the cell is empty, so you can pass through;
 * 1 means the cell contains a cherry, that you can pick up and pass
 * through;
 * -1 means the cell contains a thorn that blocks your way.
 * 
 * 
 * 
 * 
 * Your task is to collect maximum number of cherries possible by following the
 * rules below:
 * 
 * 
 * 
 * 
 * Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or
 * down through valid path cells (cells with value 0 or 1);
 * After reaching (N-1, N-1), returning to (0, 0) by moving left or up through
 * valid path cells;
 * When passing through a path cell containing a cherry, you pick it up and the
 * cell becomes an empty cell (0);
 * If there is no valid path between (0, 0) and (N-1, N-1), then no cherries
 * can be collected.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid =
 * [[0, 1, -1],
 * ⁠[1, 0, -1],
 * ⁠[1, 1,  1]]
 * Output: 5
 * Explanation: 
 * The player started at (0, 0) and went down, down, right right to reach (2,
 * 2).
 * 4 cherries were picked up during this single trip, and the matrix becomes
 * [[0,1,-1],[0,0,-1],[0,0,0]].
 * Then, the player went left, up, up, left to return home, picking up one more
 * cherry.
 * The total number of cherries picked up is 5, and this is the maximum
 * possible.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * grid is an N by N 2D array, with 1 <= N <= 50.
 * Each grid[i][j] is an integer in the set {-1, 0, 1}.
 * It is guaranteed that grid[0][0] and grid[N-1][N-1] are not
 * -1.
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
	int n;
	bool out_(int x, int y, vector<vector<int>>& grid){
		return x < 0 || y < 0 || x >= n || y >= n || grid[x][y] == -1;
	}

    int callme(int x, int y, int a, int b, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        if(out_(x, y, grid) || out_(a, b, grid))
        	return INT_MIN;
        
        if(x == a && y == b && x == n-1 && y == n-1)
        	return grid[n-1][n-1];
        
        if(dp[x][y][a] != -1)
            return dp[x][y][a];
        if(dp[a][b][x] != -1)
            return dp[a][b][x];
        
        int tmp1 = grid[x][y], tmp2 = grid[a][b];
        int ret = tmp1 + ((x==a && y==b)?0:tmp2);
        grid[x][y] = grid[a][b] = 0;
        
       	ret += max({
       		callme(x+1, y, a+1, b, grid, dp),
       		callme(x+1, y, a, b+1, grid, dp),
       		callme(x, y+1, a+1, b, grid, dp),
       		callme(x, y+1, a, b+1, grid, dp)
       	});
        grid[x][y] = tmp1; grid[a][b] = tmp2;
        
        return dp[x][y][a] = dp[a][b][x] = ret;
    }

    int cherryPickup(vector<vector<int>>& grid) {
     	n = grid.size();
     	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        return max(0, callme(0, 0, 0, 0, grid, dp));
    }
};
