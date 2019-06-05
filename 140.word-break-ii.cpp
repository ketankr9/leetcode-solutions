/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 *
 * https://leetcode.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (26.64%)
 * Likes:    927
 * Dislikes: 241
 * Total Accepted:    159.3K
 * Total Submissions: 582.6K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, add spaces in s to construct a sentence where each word is
 * a valid dictionary word. Return all such possible sentences.
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
 * Input:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * Output:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * Output:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * Explanation: Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output:
 * []
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_set<string> ss;
    vector<string> ans;
    unordered_map<int, vector<string> > mm;
    vector<string> callme(int k, string s){
        if(k >= (int)s.size()){
            return vector<string>(1, "");
        }
        if(mm.find(k)!=mm.end())
            return mm[k];
        
        vector<string> ans;
        string st = "";
        for(int i=k; i<(int)s.size(); i++){
            st+=s[i];
            if(ss.find(st)!=ss.end()){
                vector<string> tmp = callme(i+1, s);
                for(auto e: tmp)
                    ans.push_back(st+(e==""?"":" "+e));
            }
        }
        mm[k] = ans;
        return ans;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        ss.clear();
        mm.clear();
        for(auto e: wordDict)
            ss.insert(e);
       return callme(0, s);
    }
};

