/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (29.29%)
 * Total Accepted:    293.5K
 * Total Submissions: 1M
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * Note: For the purpose of this problem, we define empty string as valid
 * palindrome.
 *
 * Example 1:
 *
 *
 * Input: "A man, a plan, a canal: Panama"
 * Output: true
 *
 *
 * Example 2:
 *
 *
 * Input: "race a car"
 * Output: false
 *
 *
 */
class Solution {
public:
    bool isalphanum(char c){
      return ('0' <= c && c<= '9') || ('a' <=c && c <= 'z') || ('A' <=c && c <= 'Z');
    }
    bool isPalindrome(string s) {
        int i=0;
        int j = s.size()-1;
        if(j == -1) return true;
        while(i<j){
          if(!isalphanum(s[i]))  {  i++; continue; }
          if(!isalphanum(s[j]))  {  j--; continue; }
          if(tolower(s[i]) != tolower(s[j]))  return false;
          i++; j--;
        }
        return true;
    }
};
