/*
 * @lc app=leetcode id=1337 lang=java
 *
 * [1337] The K Weakest Rows in a Matrix
 *
 * https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/
 *
 * algorithms
 * Easy (69.06%)
 * Likes:    60
 * Dislikes: 4
 * Total Accepted:    8.6K
 * Total Submissions: 12.4K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,1,1,0],[1,0,0,0,0],[1,1,0,0,0],[1,1,1,1,1]]\n3'
 *
 * Given a m * n matrix mat of ones (representing soldiers) and zeros
 * (representing civilians), return the indexes of the k weakest rows in the
 * matrix ordered from the weakest to the strongest.
 * 
 * A row i is weaker than row j, if the number of soldiers in row i is less
 * than the number of soldiers in row j, or they have the same number of
 * soldiers but i is less than j. Soldiers are always stand in the frontier of
 * a row, that is, always ones may appear first and then zeros.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: mat = 
 * [[1,1,0,0,0],
 * ⁠[1,1,1,1,0],
 * ⁠[1,0,0,0,0],
 * ⁠[1,1,0,0,0],
 * ⁠[1,1,1,1,1]], 
 * k = 3
 * Output: [2,0,3]
 * Explanation: 
 * The number of soldiers for each row is: 
 * row 0 -> 2 
 * row 1 -> 4 
 * row 2 -> 1 
 * row 3 -> 2 
 * row 4 -> 5 
 * Rows ordered from the weakest to the strongest are [2,0,3,1,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: mat = 
 * [[1,0,0,0],
 * [1,1,1,1],
 * [1,0,0,0],
 * [1,0,0,0]], 
 * k = 2
 * Output: [0,2]
 * Explanation: 
 * The number of soldiers for each row is: 
 * row 0 -> 1 
 * row 1 -> 4 
 * row 2 -> 1 
 * row 3 -> 1 
 * Rows ordered from the weakest to the strongest are [0,2,3,1]
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * m == mat.length
 * n == mat[i].length
 * 2 <= n, m <= 100
 * 1 <= k <= m
 * matrix[i][j] is either 0 or 1.
 * 
 */

// @lc code=start
class PQCompare implements Comparator<Pair<Integer, Integer>>{
	public int compare(Pair<Integer, Integer> x, Pair<Integer, Integer> y){
		if(x.getValue() < y.getValue() || (x.getValue() == y.getValue() && x.getKey() < y.getKey()))
			return 1;
		return -1;
	}
}

class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int [] ans = new int[k];
        
        int n = mat.length;
        if(n == 0)	return ans;
        int m = mat[0].length;

        PriorityQueue<Pair<Integer, Integer>> pq = new PriorityQueue<Pair<Integer, Integer>>(new PQCompare());
        for(int i=0; i<n; i++){
        	int soldierCount = 0;
        	for(int j=0; j<m; j++)
        		if(mat[i][j] == 1)
        			soldierCount += 1;
        	pq.add(new Pair<Integer, Integer>(i, soldierCount));
        	if(pq.size() > k)
        		pq.poll();
        }

        for(int i=0; i<k; i++){
        	ans[k-i-1] = pq.poll().getKey();
        }
        return ans;
    }
}
// @lc code=end
