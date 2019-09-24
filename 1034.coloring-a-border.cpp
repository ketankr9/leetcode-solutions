/*
 * @lc app=leetcode id=1034 lang=cpp
 *
 * [1034] Coloring A Border
 *
 * https://leetcode.com/problems/coloring-a-border/description/
 *
 * algorithms
 * Medium (42.87%)
 * Total Accepted:    6K
 * Total Submissions: 14K
 * Testcase Example:  '[[1,1],[1,2]]\n0\n0\n3'
 *
 * Given a 2-dimensional grid of integers, each value in the grid represents
 * the color of the grid square at that location.
 * 
 * Two squares belong to the same connected component if and only if they have
 * the same color and are next to each other in any of the 4 directions.
 * 
 * The border of a connected component is all the squares in the connected
 * component that are either 4-directionally adjacent to a square not in the
 * component, or on the boundary of the grid (the first or last row or
 * column).
 * 
 * Given a square at location (r0, c0) in the grid and a color, color the
 * border of the connected component of that square with the given color, and
 * return the final grid.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: grid = [[1,1],[1,2]], r0 = 0, c0 = 0, color = 3
 * Output: [[3, 3], [3, 2]]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: grid = [[1,2,2],[2,3,2]], r0 = 0, c0 = 1, color = 3
 * Output: [[1, 3, 3], [2, 3, 3]]
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: grid = [[1,1,1],[1,1,1],[1,1,1]], r0 = 1, c0 = 1, color = 2
 * Output: [[2, 2, 2], [2, 1, 2], [2, 2, 2]]
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length <= 50
 * 1 <= grid[0].length <= 50
 * 1 <= grid[i][j] <= 1000
 * 0 <= r0 < grid.length
 * 0 <= c0 < grid[0].length
 * 1 <= color <= 1000
 * 
 */
class Solution {
public:
	bool outS(int& i, int& j, int n, int m){
		return i < 0 || j < 0 || i >= n || j>= m;
	}
	bool isB(int i, int j, vector<vector<int>>& grid, int& p){
		return outS(i, j, grid.size(), grid[0].size()) || (grid[i][j] > 0 && grid[i][j] != p);
	}
	void callme(int i, int j, vector<vector<int>>& grid, int& p){
		if(outS(i, j, grid.size(), grid[0].size()) || grid[i][j] !=p )	return;

		if(isB(i+1, j, grid, p) || isB(i, j+1, grid, p) || isB(i, j-1, grid, p) || isB(i-1, j, grid, p))
			grid[i][j] = -1;
		else
			grid[i][j] = -2;

		callme(i+1, j, grid, p);
		callme(i-1, j, grid, p);
		callme(i, j+1, grid, p);
		callme(i, j-1, grid, p);
	}
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
		int p = grid[r0][c0];
		callme(r0, c0, grid, p);
		for(int i=0; i<grid.size(); i++)
			for(int j=0; j<grid[0].size(); j++)
				if(grid[i][j] == -1)
					grid[i][j] = color;
				else if(grid[i][j] == -2)
					grid[i][j] = p;
		return grid;        
    }
};
