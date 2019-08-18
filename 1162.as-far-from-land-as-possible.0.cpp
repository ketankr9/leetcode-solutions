/*
 * @lc app=leetcode id=1162 lang=cpp
 *
 * [1162] As Far from Land as Possible
 *
 * https://leetcode.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (28.89%)
 * Total Accepted:    1.5K
 * Total Submissions: 5.5K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * Given an N x N grid containing only values 0 and 1, where 0 represents water
 * and 1 represents land, find a water cell such that its distance to the
 * nearest land cell is maximized and return the distance.
 * 
 * The distance used in this problem is the Manhattan distance: the distance
 * between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
 * 
 * If no land or water exists in the grid, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: [[1,0,1],[0,0,0],[1,0,1]]
 * Output: 2
 * Explanation: 
 * The cell (1, 1) is as far as possible from all the land with distance 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * 
 * 
 * Input: [[1,0,0],[0,0,0],[0,0,0]]
 * Output: 4
 * Explanation: 
 * The cell (2, 2) is as far as possible from all the land with distance
 * 4.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] is 0 or 1
 * 
 * 
 */
class Solution {
public:
    void callme(int val, int x, int y, vector<vector<int>>& grid){
        int n = grid.size(), m = grid[0].size();
        if(x == n || x == -1 || y == -1 || y == m)  return;
        if(grid[x][y] == 1 || ( grid[x][y] != 0 && grid[x][y] <= val))   return;
        grid[x][y] = val;
        callme(val+1, x+1, y, grid);
        callme(val+1, x, y+1, grid);
        callme(val+1, x, y-1, grid);
        callme(val+1, x-1, y, grid);
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for(int x=0; x<n; x++)
            for(int y=0; y<m; y++)
                if(grid[x][y] == 1){
                    callme(2, x+1, y, grid);
                    callme(2, x, y+1, grid);
                    callme(2, x, y-1, grid);
                    callme(2, x-1, y, grid);
                }
        int ans = -1;
        for(int x=0; x<n; x++)
            for(int y=0; y<m; y++)
                if(grid[x][y] != 1)
                    ans = max(grid[x][y], ans);
        return ans==-1?-1:(ans-1);
    }
};
