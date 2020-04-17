/*
 * @lc app=leetcode id=980 lang=java
 *
 * [980] Unique Paths III
 *
 * https://leetcode.com/problems/unique-paths-iii/description/
 *
 * algorithms
 * Hard (72.57%)
 * Likes:    453
 * Dislikes: 55
 * Total Accepted:    27.3K
 * Total Submissions: 37.7K
 * Testcase Example:  '[[1,0,0,0],[0,0,0,0],[0,0,2,-1]]'
 *
 * On a 2-dimensional grid, there are 4 types of squares:
 * 
 * 
 * 1 represents the starting square.  There is exactly one starting square.
 * 2 represents the ending square.  There is exactly one ending square.
 * 0 represents empty squares we can walk over.
 * -1 represents obstacles that we cannot walk over.
 * 
 * 
 * Return the number of 4-directional walks from the starting square to the
 * ending square, that walk over every non-obstacle square exactly once.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
 * Output: 2
 * Explanation: We have the following two paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
 * 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,0,0,0],[0,0,0,0],[0,0,0,2]]
 * Output: 4
 * Explanation: We have the following four paths: 
 * 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2),(2,3)
 * 2. (0,0),(0,1),(1,1),(1,0),(2,0),(2,1),(2,2),(1,2),(0,2),(0,3),(1,3),(2,3)
 * 3. (0,0),(1,0),(2,0),(2,1),(2,2),(1,2),(1,1),(0,1),(0,2),(0,3),(1,3),(2,3)
 * 4. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2),(2,3)
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [[0,1],[2,0]]
 * Output: 0
 * Explanation: 
 * There is no path that walks over every empty square exactly once.
 * Note that the starting and ending square can be anywhere in the
 * grid.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= grid.length * grid[0].length <= 20
 * 
 */

// @lc code=start
class Solution {
	int zeros = 0;
	private int callme(int x, int y, int[][] grid){
		if(x<0 || y<0 || x>=grid.length || y>=grid[0].length)
			return 0;
		if(grid[x][y] == -1 || grid[x][y] == 3)
			return 0;
		if(grid[x][y] == 2){
			if(zeros == 0)
				return 1;
			else
				return 0;
		}
		
		zeros--;
		grid[x][y] = 3;
		int ret = 0;
		
		//left
		ret += callme(x, y-1, grid);
		//right
		ret += callme(x, y+1, grid);
		//up
		ret += callme(x-1, y, grid);
		//down
		ret += callme(x+1, y, grid);
		
		zeros++;
		grid[x][y] = 0;
		return ret;
	}

    public int uniquePathsIII(int[][] grid) {

    	for(int i=0; i<grid.length; i++)
        	for(int j=0; j<grid[0].length; j++)
        		if(grid[i][j] == 0)
        			zeros++;
        for(int i=0; i<grid.length; i++)
        	for(int j=0; j<grid[0].length; j++)
        		if(grid[i][j] == 1){
        			grid[i][j] = -1;
        			return callme(i+1, j, grid)+callme(i-1, j, grid)+callme(i, j-1, grid)+callme(i, j+1, grid);
        		}

        return 0;
    }
}
// @lc code=end
