/*
 * @lc app=leetcode id=583 lang=cpp
 *
 * [583] Delete Operation for Two Strings
 *
 * https://leetcode.com/problems/delete-operation-for-two-strings/description/
 *
 * algorithms
 * Medium (44.81%)
 * Likes:    690
 * Dislikes: 18
 * Total Accepted:    31.1K
 * Total Submissions: 69.3K
 * Testcase Example:  '"sea"\n"eat"'
 *
 * 
 * Given two words word1 and word2, find the minimum number of steps required
 * to make word1 and word2 the same, where in each step you can delete one
 * character in either string.
 * 
 * 
 * Example 1:
 * 
 * Input: "sea", "eat"
 * Output: 2
 * Explanation: You need one step to make "sea" to "ea" and another step to
 * make "eat" to "ea".
 * 
 * 
 * 
 * Note:
 * 
 * The length of given words won't exceed 500.
 * Characters in given words can only be lower-case letters.
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> d(m+1);
        d[0] = 0;
        int prev;
        for(int i = 0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                if(j == 0){
                    prev = d[0];
                    d[0] = i;
                    continue;
                }
                if(i == 0){
                    d[j] = j;
                    continue;
                }
                int tmp = d[j];
                
                d[j] = 1 + min(d[j], d[j-1]);
                if(word1[i-1] == word2[j-1])
                    d[j] = min(d[j], prev);
                prev = tmp;
            }
        }
        return d[m];
    }
};

