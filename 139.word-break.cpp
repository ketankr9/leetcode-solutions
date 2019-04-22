/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (34.30%)
 * Total Accepted:    323.6K
 * Total Submissions: 926.2K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool find(string s, int start, vector<string>& wordDict, int *arr){
        // cout<<start<<" ";
        if(start == s.size())
            return true;

        if(arr[start] != -1)
            return arr[start];
        arr[start] = 0;
        for(auto st: wordDict){
            if(s.substr(start, st.size()) == st){
                if(find(s, start+st.size(), wordDict, arr)){
                    arr[start] = true;
                    break;
                }
            }
        }
        
        return arr[start];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int match[s.size()+1];
        fill_n(match, s.size()+1, -1);
        return find(s, 0, wordDict, match);
    }
};
