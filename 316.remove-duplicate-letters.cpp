/*
 * @lc app=leetcode id=316 lang=cpp
 *
 * [316] Remove Duplicate Letters
 *
 * https://leetcode.com/problems/remove-duplicate-letters/description/
 *
 * algorithms
 * Hard (31.91%)
 * Total Accepted:    57K
 * Total Submissions: 175.3K
 * Testcase Example:  '"bcabc"'
 *
 * Given a string which contains only lowercase letters, remove duplicate
 * letters so that every letter appear once and only once. You must make sure
 * your result is the smallest in lexicographical order among all possible
 * results.
 * 
 * Example 1:
 * 
 * 
 * Input: "bcabc"
 * Output: "abc"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "cbacdcbc"
 * Output: "acdb"
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<int> st;
        vector<bool> used(26, false);
        vector<int> cnt(26, 0);
        for(auto e: s)
            cnt[e-'a']++;
        for(auto e: s){
            cnt[e-'a']--;
            if(used[e-'a']) continue;
            while(!st.empty() && st.top() > (e-'a') && cnt[st.top()]>0)
                used[st.top()] = false, st.pop();
            st.push(e-'a');
            used[e-'a'] = true;
        }
        string ans = "";
        while(!st.empty())
            ans = (char)('a'+st.top())+ans, st.pop();
        return ans;  
    }
};
