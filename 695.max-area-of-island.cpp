/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * https://leetcode.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (57.46%)
 * Total Accepted:    86.5K
 * Total Submissions: 150K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's
 * (representing land) connected 4-directionally (horizontal or vertical.) You
 * may assume all four edges of the grid are surrounded by water.
 * 
 * Find the maximum area of an island in the given 2D array. (If there is no
 * island, the maximum area is 0.)
 * 
 * Example 1:
 * 
 * 
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 * 
 * Given the above grid, return 6. Note the answer is not 11, because the
 * island must be connected 4-directionally.
 * 
 * Example 2:
 * 
 * 
 * [[0,0,0,0,0,0,0,0]]
 * Given the above grid, return 0.
 * 
 * Note: The length of each dimension in the given grid does not exceed 50.
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cnt;
    int maxx;
    void callme(int x, int y, vector<vector<int>>& grid, const int n, const int m){
        if(x < 0 || y < 0 || x>=n || y>= m || grid[x][y] == 0){
            maxx = max(maxx, cnt);
            return;
        }
        grid[x][y] = 0;
        cnt++;
        callme(x+1, y, grid, n, m);
        callme(x, y+1, grid, n, m);
        callme(x-1, y, grid, n, m);
        callme(x, y-1, grid, n, m);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        maxx = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 1){
                    cnt = 0;
                    callme(i, j, grid, n, m);
                }
        return maxx;
    }
};
