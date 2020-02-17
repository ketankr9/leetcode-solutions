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
        int[] prev = new int[n];
        int[] cur = new int[n];
        
        for(int i=0; i+1<n; i++)
        	cur[i] = s.charAt(i) == s.charAt(i+1) ? 0 : 1;

        for(int k=2; k<n; k++){
        	for(int i=0; i+k<n; i++)
        		if(s.charAt(i) == s.charAt(i+k))
        			prev[i] = prev[i+1];
        		else
        			prev[i] = 1 + Math.min(cur[i], cur[i+1]);
        	int[] tmp = prev;
        	prev = cur;
        	cur = tmp;
        }

        return cur[0];
    }
}
// @lc code=end
