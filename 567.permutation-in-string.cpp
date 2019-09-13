/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (39.17%)
 * Total Accepted:    57.9K
 * Total Submissions: 147.8K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab" s2 = "eidbaooo"
 * Output: True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * 
 * 
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    	if(s1.empty())	return true;
    	if(s1.size() > s2.size())	return false;
        vector<int> cnt(26, 0);
        int len = s1.size();
        for(auto const& c: s1)
        	cnt[c-'a']++;
        vector<int> tmp(26, 0);
        int j = 0;
        for(int i=0; i<s2.size(); i++){
        	tmp[s2[i]-'a']++;
        	if(i < len-1)	continue;
        	if(tmp == cnt)	return true;
        	tmp[s2[j++]-'a']--;
        }
        return false;
    }
};
