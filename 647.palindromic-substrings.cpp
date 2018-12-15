/*
 * @lc app=leetcode id=647 lang=cpp
 *
 * [647] Palindromic Substrings
 *
 * https://leetcode.com/problems/palindromic-substrings/description/
 *
 * algorithms
 * Medium (54.71%)
 * Total Accepted:    71.4K
 * Total Submissions: 130.3K
 * Testcase Example:  '"abc"'
 *
 *
 * Given a string, your task is to count how many palindromic substrings in
 * this string.
 *
 *
 *
 * The substrings with different start indexes or end indexes are counted as
 * different substrings even they consist of same characters.
 *
 *
 * Example 1:
 *
 * Input: "abc"
 * Output: 3
 * Explanation: Three palindromic strings: "a", "b", "c".
 *
 *
 *
 * Example 2:
 *
 * Input: "aaa"
 * Output: 6
 * Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 *
 *
 *
 * Note:
 *
 * The input string length won't exceed 1000.
 *
 *
 */
class Solution {
public:
    int count;
    void centerAt(int i, string s, bool dual){
      int c = 0;
      if(dual){
        if(s[i]!=s[i+1])  return;
        while(0<=i-c && i+1+c<(int)s.size() && s[i-c] == s[i+1+c]){
          c++;
        }
      }else{ //center at single
        while(0<=i-c && i+c<(int)s.size() && s[i-c]==s[i+c]){
          c++;
        }
      }
      count += c;
      return;
    }
    int countSubstrings(string s) {
      if((int)s.size() == 0)  return 0;
      count = 1;
      for(int i=0;i<(int)s.size()-1;i++){
        centerAt(i,s, false);
        centerAt(i,s, true);
      }
      return count;
    }
};
