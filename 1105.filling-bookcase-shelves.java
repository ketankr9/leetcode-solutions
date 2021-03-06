/*
 * @lc app=leetcode id=1105 lang=java
 *
 * [1105] Filling Bookcase Shelves
 *
 * https://leetcode.com/problems/filling-bookcase-shelves/description/
 *
 * algorithms
 * Medium (57.28%)
 * Likes:    399
 * Dislikes: 22
 * Total Accepted:    10.5K
 * Total Submissions: 18.3K
 * Testcase Example:  '[[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]\n4'
 *
 * We have a sequence of books: the i-th book has thickness books[i][0] and
 * height books[i][1].
 * 
 * We want to place these books in order onto bookcase shelves that have total
 * width shelf_width.
 * 
 * We choose some of the books to place on this shelf (such that the sum of
 * their thickness is <= shelf_width), then build another level of shelf of the
 * bookcase so that the total height of the bookcase has increased by the
 * maximum height of the books we just put down.  We repeat this process until
 * there are no more books to place.
 * 
 * Note again that at each step of the above process, the order of the books we
 * place is the same order as the given sequence of books.  For example, if we
 * have an ordered list of 5 books, we might place the first and second book
 * onto the first shelf, the third book on the second shelf, and the fourth and
 * fifth book on the last shelf.
 * 
 * Return the minimum possible height that the total bookshelf can be after
 * placing shelves in this manner.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelf_width = 4
 * Output: 6
 * Explanation:
 * The sum of the heights of the 3 shelves are 1 + 3 + 2 = 6.
 * Notice that book number 2 does not have to be on the first shelf.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= books.length <= 1000
 * 1 <= books[i][0] <= shelf_width <= 1000
 * 1 <= books[i][1] <= 1000
 * 
 * 
 */

// @lc code=start
class Solution {
	private int[] dp;
	private int f(int pos, int[][] books, int self_width){
		if(pos >= books.length)
			return 0;
		
		if(dp[pos] != 0)
			return dp[pos];
		int i = pos, width = 0;
		int ret = Integer.MAX_VALUE, maxh = Integer.MIN_VALUE;
		
		while(i<books.length && width+books[i][0]<=self_width){
			maxh = Integer.max(maxh, books[i][1]);
			ret  = Integer.min(ret, maxh+f(i+1, books, self_width));
			width += books[i++][0];
		}
		return dp[pos] = ret;
	}

    public int minHeightShelves(int[][] books, int shelf_width) {
        dp = new int[books.length];
        return f(0, books, shelf_width);
    }
}
// @lc code=end
