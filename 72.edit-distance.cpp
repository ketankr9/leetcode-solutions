/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (36.40%)
 * Likes:    2082
 * Dislikes: 30
 * Total Accepted:    175.2K
 * Total Submissions: 463K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
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
        int prev;
        d[0] = 0;
        for(int i=0; i<n+1; i++){
            for(int j=0; j<m+1; j++){
                if(i == 0){ d[j] = j; continue; }
                if(j == 0){
                    prev = d[0];
                    d[0] = i;
                    continue;
                }
                int tmp = d[j];
                d[j] = min(d[j]+1, min(d[j-1]+1, prev+!(word1[i-1]==word2[j-1])));
                // cout<<d[j]<<" ";
                prev = tmp;
            }
            cout<<endl;
        }
        return d[m];
    }
};

