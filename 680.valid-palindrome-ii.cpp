/*
 * @lc app=leetcode id=680 lang=cpp
 *
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (33.18%)
 * Total Accepted:    54.1K
 * Total Submissions: 163K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */
class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = (int)s.size()-1;
        while(i<j && s[i]==s[j]){
            i++;
            j--;
        }
        if(i >= j)  return true;
        
        if(s[i] != s[j-1] && s[i+1] != s[j])  return false;
        else if(s[i+1] == s[j] && s[i] == s[j-1]){
            int I = i, J = j;
            i++;
            while(i<j && s[i]==s[j]){
                i++;
                j--;
            }if(i>=j) return true;
            i = I, j = J;
            j--;
            while(i<j && s[i]==s[j]){
                i++;
                j--;
            }if(i>=j) return true;

            return false;
        }

        // Either one matches
        if(s[i] == s[j-1]) j--;
        else if(s[i+1] == s[j]) i++;
        while(i<j && s[i]==s[j]){
                i++;
                j--;
            }
        if(i<j) return false;
        return true;
    }
};
