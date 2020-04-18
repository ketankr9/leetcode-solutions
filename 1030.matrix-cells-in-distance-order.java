/*
 * @lc app=leetcode id=1030 lang=java
 *
 * [1030] Matrix Cells in Distance Order
 *
 * https://leetcode.com/problems/matrix-cells-in-distance-order/description/
 *
 * algorithms
 * Easy (65.08%)
 * Likes:    173
 * Dislikes: 83
 * Total Accepted:    20.1K
 * Total Submissions: 30.9K
 * Testcase Example:  '1\n2\n0\n0'
 *
 * We are given a matrix with R rows and C columns has cells with integer
 * coordinates (r, c), where 0 <= r < R and 0 <= c < C.
 * 
 * Additionally, we are given a cell in that matrix with coordinates (r0, c0).
 * 
 * Return the coordinates of all cells in the matrix, sorted by their distance
 * from (r0, c0) from smallest distance to largest distance.  Here, the
 * distance between two cells (r1, c1) and (r2, c2) is the Manhattan distance,
 * |r1 - r2| + |c1 - c2|.  (You may return the answer in any order that
 * satisfies this condition.)
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: R = 1, C = 2, r0 = 0, c0 = 0
 * Output: [[0,0],[0,1]]
 * Explanation: The distances from (r0, c0) to other cells are: [0,1]
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: R = 2, C = 2, r0 = 0, c0 = 1
 * Output: [[0,1],[0,0],[1,1],[1,0]]
 * Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2]
 * The answer [[0,1],[1,1],[0,0],[1,0]] would also be accepted as correct.
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: R = 2, C = 3, r0 = 1, c0 = 2
 * Output: [[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
 * Explanation: The distances from (r0, c0) to other cells are: [0,1,1,2,2,3]
 * There are other answers that would also be accepted as correct, such as
 * [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= R <= 100
 * 1 <= C <= 100
 * 0 <= r0 < R
 * 0 <= c0 < C
 * 
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
    public int[][] allCellsDistOrder(int R, int C, int r0, int c0) {
        int[][] ans = new int[R*C][2];

        int k = 1;
        ans[0][0] = r0;
        ans[0][1] = c0;
        
        for(int d=1; d<R+C; d++)
        	for(int i=0; i<R; i++)
        		for(int j=0; j<C; j++)
        			if(Math.abs(i-r0) + Math.abs(j-c0) == d){
        				ans[k][0] = i;
        				ans[k][1] = j;
        				k++;
        			}
        		
        return ans;
    }
}
        // int n = R*C, k = 0, d = 1;
        // ans[k++] = {r0, c0};
        // while(d < R+C-1){
        // 	//up
        // 	ans[k++] = {r0-d, c0};
        // 	for(int y = c0+1, x = r0-d+1; y<c0+d && x<r0; y++, x++)
        // 		ans[k++] = {x, y};
        // 	//right
        // 	for(int y = c0+d-1, x = r0+1; y>c0 && x<r0+d; y--, x++)
        // 		ans[k++] = {x, y};
        // 	//down
        // 	for(int y = c0+1, x = r0-d+1; y<c0+d && x<r0; y--, x--)
        // 		ans[k++] = {x, y};
        // 	for(int y = c0+1, x = r0-d+1; y<c0+d && x<r0; y++, x++)
        // 		ans[k++] = {x, y};
        // }
// @lc code=end
