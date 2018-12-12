/*
 * @lc app=leetcode id=463 lang=cpp
 *
 * [463] Island Perimeter
 *
 * https://leetcode.com/problems/island-perimeter/description/
 *
 * algorithms
 * Easy (59.36%)
 * Total Accepted:    110.1K
 * Total Submissions: 185.6K
 * Testcase Example:  '[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]'
 *
 * You are given a map in form of a two-dimensional integer grid where 1
 * represents land and 0 represents water.
 *
 * Grid cells are connected horizontally/vertically (not diagonally). The grid
 * is completely surrounded by water, and there is exactly one island (i.e.,
 * one or more connected land cells).
 *
 * The island doesn't have "lakes" (water inside that isn't connected to the
 * water around the island). One cell is a square with side length 1. The grid
 * is rectangular, width and height don't exceed 100. Determine the perimeter
 * of the island.
 *
 *
 *
 * Example:
 *
 *
 * Input:
 * [[0,1,0,0],
 * ⁠[1,1,1,0],
 * ⁠[0,1,0,0],
 * ⁠[1,1,0,0]]
 *
 * Output: 16
 *
 * Explanation: The perimeter is the 16 yellow stripes in the image below:
 *
 *
 *
 *
 */
class Solution {
public:
  int ROW,COL;
  int sum;
  void floodFill(vector<vector<int>>& grid, int i, int j, bool *visited){
      if(i<0 || i>=ROW || j<0 || j>=COL)
        return;
      if(!grid[i][j] || visited[i*COL+j])
        return;
      // int sum = 0;
      // right, j++
      if(j==COL-1 || !grid[i][j+1]){
        sum++;
      }
      // left, j--
      if(j==0 || !grid[i][j-1])
        sum++;
      // up, i--
      if(i==0 || !grid[i-1][j])
        sum++;
      // down, i++
      if(i==ROW-1 || !grid[i+1][j])
        sum++;
      visited[i*COL+j] = true;
      // if(i+1 < ROW && grid[i+1][j] && !visited[(i+1)*COL+j])
      floodFill(grid, i+1, j, visited);
      // if(i-1>=0 && grid[i-1][j] && !visited[(i-1)*COL+j])
      floodFill(grid, i-1, j, visited);
      // if(j+1<COL && grid[][])
      floodFill(grid, i, j+1, visited);
      floodFill(grid, i, j-1, visited);
  }
    int islandPerimeter(vector<vector<int>>& grid) {
        ROW = grid.size();  if(!ROW)  return 0;
        COL = grid[0].size();
        sum = 0;
        bool visited[ROW*COL];
        fill_n(visited, ROW*COL, false);

        for(int i=0;i<ROW;i++)
          for(int j=0;j<COL;j++)
            if(grid[i][j]){
              floodFill(grid, i, j, visited);
              return sum;
            }
        return 0;
    }

};
