/*
 * @lc app=leetcode id=1329 lang=java
 *
 * [1329] Sort the Matrix Diagonally
 *
 * https://leetcode.com/problems/sort-the-matrix-diagonally/description/
 *
 * algorithms
 * Medium (77.53%)
 * Likes:    83
 * Dislikes: 30
 * Total Accepted:    4.7K
 * Total Submissions: 6K
 * Testcase Example:  '[[3,3,1,1],[2,2,1,2],[1,1,1,2]]'
 *
 * Given a m * n matrix mat of integers, sort it diagonally in ascending order
 * from the top-left to the bottom-right then return the sorted array.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
 * Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 1 <= m, n <= 100
 * 1 <= mat[i][j] <= 100
 * 
 */

// @lc code=start
class Solution {
	public void sortme(int x, int y, int[][] mat){
		ArrayList<Integer> arr = new ArrayList<Integer>();
		int a = x, b = y;
		
		while(a<mat.length && b<mat[0].length)
			arr.add(mat[a++][b++]);
		
		Collections.sort(arr);
		
		int i = 0;
		while(x<mat.length && y<mat[0].length)
			mat[x++][y++] = arr.get(i++);
	}

    public int[][] diagonalSort(int[][] mat) {

        for(int i=0; i<mat[0].length; i++)
        	sortme(0, i, mat);
        for(int i=0; i<mat.length; i++)
        	sortme(i, 0, mat);

        return mat;
    }
}
// @lc code=end
