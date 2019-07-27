/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 *
 * https://leetcode.com/problems/longest-palindromic-subsequence/description/
 *
 * algorithms
 * Medium (47.54%)
 * Total Accepted:    65.7K
 * Total Submissions: 138.2K
 * Testcase Example:  '"bbbab"'
 *
 * 
 * Given a string s, find the longest palindromic subsequence's length in s.
 * You may assume that the maximum length of s is 1000.
 * 
 * 
 * Example 1:
 * Input: 
 * 
 * "bbbab"
 * 
 * Output: 
 * 
 * 4
 * 
 * One possible longest palindromic subsequence is "bbbb".
 * 
 * 
 * Example 2:
 * Input:
 * 
 * "cbbd"
 * 
 * Output:
 * 
 * 2
 * 
 * One possible longest palindromic subsequence is "bb".
 * 
 */
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mm;
    int callme(int x, int y, string& s){
        if(x>y)
            return 0;

        if(mm.find(x)!=mm.end() && mm[x].find(y)!=mm[x].end())
            return mm[x][y];

        int ans = 0;
        if(s[x] == s[y])
            ans = (x==y?1:2) + callme(x+1, y-1, s);
        else
            ans = max(callme(x+1, y, s), callme(x, y-1, s));
        mm[x][y] = ans;

        return ans;
    }
    int longestPalindromeSubseq(string s) {
        mm.clear();
        return callme(0, (int)s.size()-1, s);
    }
};
