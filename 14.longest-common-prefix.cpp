/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 *
 * https://leetcode.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (32.46%)
 * Total Accepted:    370.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * Write a function to find the longest common prefix string amongst an array
 * of strings.
 * 
 * If there is no common prefix, return an empty string "".
 * 
 * Example 1:
 * 
 * 
 * Input: ["flower","flow","flight"]
 * Output: "fl"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ["dog","racecar","car"]
 * Output: ""
 * Explanation: There is no common prefix among the input strings.
 * 
 * 
 * Note:
 * 
 * All given inputs are in lowercase letters a-z.
 * 
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int k = 0;
        int i = 0;
        int N = strs.size();
        if(N == 0) return "";
        string ans = "";
        while(i == 0 && k < (int)strs[0].size()){
            while(i<N-1 && strs[i][k] == strs[i+1][k]){
                i++;
            }
            if(i == N-1){
                ans += strs[i][k];
                k++;
                i=0;
            }else
                break;
        }

        return ans;
    }
};
