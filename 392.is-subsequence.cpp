/*
 * @lc app=leetcode id=392 lang=cpp
 *
 * [392] Is Subsequence
 *
 * https://leetcode.com/problems/is-subsequence/description/
 *
 * algorithms
 * Medium (46.18%)
 * Total Accepted:    88.5K
 * Total Submissions: 189.2K
 * Testcase Example:  '"abc"\n"ahbgdc"'
 *
 * 
 * Given a string s and a string t, check if s is subsequence of t.
 * 
 * 
 * 
 * You may assume that there is only lower case English letters in both s and
 * t. t is potentially a very long (length ~= 500,000) string, and s is a short
 * string (
 * 
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ace" is a
 * subsequence of "abcde" while "aec" is not).
 * 
 * 
 * Example 1:
 * s = "abc", t = "ahbgdc"
 * 
 * 
 * Return true.
 * 
 * 
 * Example 2:
 * s = "axc", t = "ahbgdc"
 * 
 * 
 * Return false.
 * 
 * 
 * Follow up:
 * If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you
 * want to check one by one to see if T has its subsequence. In this scenario,
 * how would you change your code?
 * 
 * Credits:Special thanks to @pbrother for adding this problem and creating all
 * test cases.
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, queue<int> > q;
        // vector<int> pos(26, 0);

        for(int i=0; i<(int)t.size(); i++)
            q[t[i]].push(i);
        
        int prev = -1;
        // for(auto it: q){
        //     cout<<it.first<<"::\n";
        //     if(it.first == 'y') continue;
        //     while(!it.second.empty()){
        //         cout<<it.second.front()<<" ";
        //         it.second.pop();
        //         }
        // }
        for(auto e: s){
            while(!q[e].empty() && q[e].front() < prev)
                q[e].pop();
            // cout<<e<<":"<<q[e].front()<<"  ";
            if(q[e].empty())   return false;
            prev = q[e].front();
            q[e].pop();
        }

        return true;
    }
};
