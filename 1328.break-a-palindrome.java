/*
 * @lc app=leetcode id=1328 lang=java
 *
 * [1328] Break a Palindrome
 *
 * https://leetcode.com/problems/break-a-palindrome/description/
 *
 * algorithms
 * Medium (40.41%)
 * Likes:    48
 * Dislikes: 36
 * Total Accepted:    4.3K
 * Total Submissions: 10.7K
 * Testcase Example:  '"abccba"'
 *
 * Given a palindromic string palindrome, replace exactly one character by any
 * lowercase English letter so that the string becomes the lexicographically
 * smallest possible string that isn't a palindrome.
 * 
 * After doing so, return the final string.  If there is no way to do so,
 * return the empty string.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: palindrome = "abccba"
 * Output: "aaccba"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: palindrome = "a"
 * Output: ""
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= palindrome.length <= 1000
 * palindrome consists of only lowercase English letters.
 * 
 */

// @lc code=start
class Solution {
    public String breakPalindrome(String palindrome) {
        if(palindrome.length() == 1)	return "";

        char[] arr = palindrome.toCharArray();
        int i = 0;
        for(i=0; i*2<arr.length; i++){
        	if(arr[i] == 'a' || (arr.length%2==1 && (i*2+1) == arr.length))
        		continue;
        	arr[i] = 'a';
        	return String.valueOf(arr);
        }
        arr[arr.length-1] = 'b';
        return String.valueOf(arr);
    }
}
// @lc code=end
