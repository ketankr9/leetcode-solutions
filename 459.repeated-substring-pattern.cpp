/*
 * @lc app=leetcode id=459 lang=cpp
 *
 * [459] Repeated Substring Pattern
 *
 * https://leetcode.com/problems/repeated-substring-pattern/description/
 *
 * algorithms
 * Easy (40.07%)
 * Total Accepted:    82.8K
 * Total Submissions: 206.5K
 * Testcase Example:  '"abab"'
 *
 * Given a non-empty string check if it can be constructed by taking a
 * substring of it and appending multiple copies of the substring together. You
 * may assume the given string consists of lowercase English letters only and
 * its length will not exceed 10000.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "abab"
 * Output: True
 * Explanation: It's the substring "ab" twice.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "aba"
 * Output: False
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "abcabcabcabc"
 * Output: True
 * Explanation: It's the substring "abc" four times. (And the substring
 * "abcabc" twice.)
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repe(const string &s, int k, int n){
        string temp = "";
        for(int i=1; i<=n/k; i++)
            temp += s.substr(0, k);
        return temp == s;
    }
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        for(int i=1; i<n; i++){
            if(n%i==0 && repe(s, i, n))
                return true;
        }        
    return false;
    }
};
