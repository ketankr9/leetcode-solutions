/*
 * @lc app=leetcode id=367 lang=java
 *
 * [367] Valid Perfect Square
 *
 * https://leetcode.com/problems/valid-perfect-square/description/
 *
 * algorithms
 * Easy (40.84%)
 * Likes:    595
 * Dislikes: 134
 * Total Accepted:    142.2K
 * Total Submissions: 348.1K
 * Testcase Example:  '16'
 *
 * Given a positive integer num, write a function which returns True if num is
 * a perfect square else False.
 * 
 * Note: Do not use any built-in library function such as sqrt.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 14
 * Output: false
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
    public boolean isPerfectSquare(int num) {
        long mid = -1;
        for(long d=num/2; d>=1; d/=2)
        	while( (mid+d)*(mid+d) <= (long)num )
        		mid += d;
        return mid*mid == (long)num;
    }
}
// @lc code=end
