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

    public int minInsertions(String s) {
        int n = s.length();
        int[][] dp = new int[n][n];
        
        for(int i=0; i<n-1; i++){
        	dp[i][i] = 0;
        	dp[i][i+1] = (s.charAt(i) == s.charAt(i+1) ? 0 : 1);
        }
        dp[n-1][n-1] = 0;

        for(int k=2; k<n; k++)
        	for(int i=0; i+k<n; i++)
        		if(s.charAt(i) == s.charAt(i+k))
        			dp[i][i+k] = dp[i+1][i+k-1];
        		else
        			dp[i][i+k] = 1 + Integer.min(dp[i][i+k-1], dp[i+1][i+k]);

        return dp[0][n-1];
    }
}
// @lc code=end
