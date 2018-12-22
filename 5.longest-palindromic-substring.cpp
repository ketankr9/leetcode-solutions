/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 *
 * https://leetcode.com/problems/longest-palindromic-substring/description/
 *
 * algorithms
 * Medium (25.84%)
 * Total Accepted:    426.8K
 * Total Submissions: 1.7M
 * Testcase Example:  '"babad"'
 *
 * Given a string s, find the longest palindromic substring in s. You may
 * assume that the maximum length of s is 1000.
 * 
 * Example 1:
 * 
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * 
 */
class Solution {
public:
    int maxLength;
    string ans = "";
    void callme(string s, int i, bool dual){
        int N = s.size();
        if(dual){
            int j = i+1;
            while(i>=0 && j<N && s[i] == s[j]){
                if(j - i > maxLength){
                    ans = s.substr(i, j-i+1);
                    maxLength = j-i;
                }
                i--;
                j++;
            }
        }else{ // single
            int j = 0;
            while(i-j>=0 && i+j < N && s[i-j] == s[i+j]){
                if(2*j > maxLength){
                    ans = s.substr(i-j,2*j+1); maxLength = 2*j;
                }
                j++;
            }
        }
    }

    string longestPalindrome(string s) {
        int N = s.size();
        maxLength = INT_MIN;
        for(int i=0;i<N-1;i++){
            callme(s, i, true);
            callme(s, i, false);
        }
        callme(s, N-1, false);
        return ans;
    }
};
