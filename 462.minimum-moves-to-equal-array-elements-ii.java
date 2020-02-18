/*
 * @lc app=leetcode id=462 lang=java
 *
 * [462] Minimum Moves to Equal Array Elements II
 *
 * https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/
 *
 * algorithms
 * Medium (53.18%)
 * Likes:    432
 * Dislikes: 41
 * Total Accepted:    41.4K
 * Total Submissions: 77.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a non-empty integer array, find the minimum number of moves required
 * to make all array elements equal, where a move is incrementing a selected
 * element by 1 or decrementing a selected element by 1.
 * 
 * You may assume the array's length is at most 10,000.
 * 
 * Example:
 * 
 * Input:
 * [1,2,3]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * Only two moves are needed (remember each move increments or decrements one
 * element):
 * 
 * [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
 * 
 * 
 */

// @lc code=start
class Solution {
    public int minMoves2(int[] nums) {
        int n = nums.length;
    	if(n <= 1)	return 0;

        Arrays.sort(nums);
        
        long total = 0l;
        for(int e: nums)	total += (long)e;

    	long ans = Long.MAX_VALUE, sumTillNow = 0;
    	for(int i=0; i<n; i++){
    		long cur = (long)nums[i];
    		sumTillNow += cur;
    		long tmp = ((long)(i+1)*cur - sumTillNow) + (total-sumTillNow - ((long)n-(long)(i+1))*cur);
    		ans = Math.min(ans, tmp); 
    	}

    	return (int)ans;
    }
}
// @lc code=end
