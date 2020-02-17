/*
 * @lc app=leetcode id=1312 lang=java
 *
 * [1312] Minimum Insertion Steps to Make a String Palindrome
 *
 * https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
 *
 * algorithms
 * Hard (55.02%)
 * Likes:    143
 * Dislikes: 5
 * Total Accepted:    5.7K
 * Total Submissions: 10.4K
 * Testcase Example:  '"zzazz"'
 *
 * Given a string s. In one step you can insert any character at any index of
 * the string.
 * 
 * Return the minimum number of steps to make s palindrome.
 * 
 * A Palindrome String is one that reads the same backward as well as
 * forward.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "zzazz"
 * Output: 0
 * Explanation: The string "zzazz" is already palindrome we don't need any
 * insertions.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "mbadm"
 * Output: 2
 * Explanation: String can be "mbdadbm" or "mdbabdm".
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "leetcode"
 * Output: 5
 * Explanation: Inserting 5 characters the string becomes "leetcodocteel".
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: s = "g"
 * Output: 0
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: s = "no"
 * Output: 1
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length <= 500
 * All characters of s are lower case English letters.
 * 
 */

// @lc code=start
class Solution {
	int[][] dp;
	private int f(int l, int r, String s){
		if(l>=r)	return 0;
		if(dp[l][r] != -1)
			return dp[l][r];
		if(s.charAt(l) == s.charAt(r))
			return f(l+1, r-1, s);
		return dp[l][r] = 1 + Integer.min(f(l+1, r, s), f(l, r-1, s));
	}

    public int minInsertions(String s) {
        dp = new int[s.length()][s.length()];
        for(int[] tmp: dp)
        	Arrays.fill(tmp, -1);
        return f(0, s.length()-1, s);
    }
}
// @lc code=end
