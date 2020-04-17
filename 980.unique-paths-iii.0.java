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
	int n, m;
	HashMap<Integer, Integer> dp;

	int p(int x, int y){ return x*m+y; }
	
	int callme(int x, int y, int[][] grid, int cur){
		if(x<0 || y<0 || x>=grid.length || y>=grid[0].length || grid[x][y] == -1)
			return 0;
		if(grid[x][y] == 2)
			return cur == 0 ? 1 : 0;
		if((cur&(1<<p(x, y))) == 0)
			return 0;

		if( dp.containsKey(cur*n*m + p(x, y)) )
			return dp.get(cur*n*m + p(x, y));

		int ret = 0;
		cur ^= (1<<p(x, y));

		//left
		ret += callme(x, y-1, grid, cur);
		//right
		ret += callme(x, y+1, grid, cur);
		//up
		ret += callme(x-1, y, grid, cur);
		//down
		ret += callme(x+1, y, grid, cur);
		
		cur ^= (1<<p(x, y));

		dp.put(cur*n*m + p(x, y), ret);
		return ret;
	}

    public int uniquePathsIII(int[][] grid) {
        int cur = 0, x = 0, y = 0; n = grid.length; m = grid[0].length;
        dp = new HashMap<Integer, Integer>();

        for(int i=0; i<n; i++)
        	for(int j=0; j<m; j++){
        		if(grid[i][j] == 0) //free
        			cur ^= (1<<p(i, j));
        		else if(grid[i][j] == 1){
        			x = i;
        			y = j;
        		}
        	}

        grid[x][y] = -1;
		return callme(x+1, y, grid, cur)+callme(x-1, y, grid, cur)+callme(x, y-1, grid, cur)+callme(x, y+1, grid, cur);

    }
}
// @lc code=end
