/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (28.12%)
 * Likes:    810
 * Dislikes: 38
 * Total Accepted:    114.2K
 * Total Submissions: 404.3K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int, int> > > mm;
    bool callme(int i, int j, int k, const string &s1, const string &s2, const string &s3){
        if(i==-1 && j==-1 && k==-1){
            // found = true;
            mm[i][j][k] = true;
            return true;
        }
        if(mm.count(i)!=0 && mm[i].count(j)!=0 && mm[i][j].count(k)!=0)
            return mm[i][j][k];
        bool found = false;
        if(i>=0 && k>=0 && s1[i] == s3[k])
            found |= callme(i-1, j, k-1, s1, s2, s3);
        if(j>=0 && k>=0 && s2[j] == s3[k])
            found |= callme(i, j-1, k-1, s1, s2, s3);
        mm[i][j][k] = found;
        return found;
    }
    bool isInterleave(string s1, string s2, string s3) {
        // found = false;
        mm.clear();
        return callme(s1.size()-1, s2.size()-1, s3.size()-1, s1, s2, s3);
        // return mm[s1.size()-1][s2.size()-1][s3.size()-1];
    }
};

