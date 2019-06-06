/*
 * @lc app=leetcode id=712 lang=cpp
 *
 * [712] Minimum ASCII Delete Sum for Two Strings
 *
 * https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
 *
 * algorithms
 * Medium (53.32%)
 * Total Accepted:    20.7K
 * Total Submissions: 38K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * Given two strings s1, s2, find the lowest ASCII sum of deleted characters to
 * make two strings equal.
 * 
 * Example 1:
 * 
 * Input: s1 = "sea", s2 = "eat"
 * Output: 231
 * Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to
 * the sum.
 * Deleting "t" from "eat" adds 116 to the sum.
 * At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum
 * possible to achieve this.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: s1 = "delete", s2 = "leet"
 * Output: 403
 * Explanation: Deleting "dee" from "delete" to turn the string into "let",
 * adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e]
 * to the sum.
 * At the end, both strings are equal to "let", and the answer is
 * 100+101+101+101 = 403.
 * If instead we turned both strings into "lee" or "eet", we would get answers
 * of 433 or 417, which are higher.
 * 
 * 
 * 
 * Note:
 * 0 < s1.length, s2.length .
 * All elements of each string will have an ASCII value in [97, 122]. 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<int> d(m+1);
        int prev;
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i == 0){
                    if(j == 0)
                        d[j] = 0;
                    else
                        d[j] = d[j-1] + s2[j-1];
                    continue; 
                }
                if(j == 0){
                    prev = d[0];
                    d[0] = prev + s1[i-1];
                    continue; 
                }
                int tmp = d[j];
                int t;
                if(s1[i-1] == s2[j-1]){
                    t = prev;
                }else{
                    t = min(d[j]+s1[i-1], d[j-1]+s2[j-1]);
                }
                d[j] = t;
                prev = tmp;
            }
        }
        return d[m];
    }
};
