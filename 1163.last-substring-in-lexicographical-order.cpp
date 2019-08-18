/*
 * @lc app=leetcode id=1163 lang=cpp
 *
 * [1163] Last Substring in Lexicographical Order
 *
 * https://leetcode.com/problems/last-substring-in-lexicographical-order/description/
 *
 * algorithms
 * Hard (21.44%)
 * Total Accepted:    1.4K
 * Total Submissions: 6.2K
 * Testcase Example:  '"abab"'
 *
 * Given a string s, return the last substring of s in lexicographical
 * order.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abab"
 * Output: "bab"
 * Explanation: The substrings are ["a", "ab", "aba", "abab", "b", "ba",
 * "bab"]. The lexicographically maximum substring is "bab".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "leetcode"
 * Output: "tcode"
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= s.length <= 10^5
 * s contains only lowercase English letters.
 * 
 * 
 */
class Solution {
public:
    string lastSubstring(string s) {
        int i=0, j=1;
        int n = s.size();
        int start = 0;
        while(j<n && i<n){
            while(j<n && s[j] > s[i]){
                i = j;
                start = i;
                j = i+1;
            }
            while(j<n && s[i] > s[j])
                j++;
            // if(j == n)  break;
            int tmp = j, tmp2 = i;
            while(j<n && s[i] == s[j])
                i++, j++;
            if(i>=j){
                i = start;
                continue;
            }

            if(j<n && s[j] > s[i])
                start = tmp, i = tmp, j = tmp+1;
            else if(j<n)
                i = tmp2;
        }

        return s.substr(start);
    }
};
