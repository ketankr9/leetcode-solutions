/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (30.51%)
 * Total Accepted:    348.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())	return 0;
        if(needle.size() > haystack.size())	return -1;

        string tmp = "";
        int k = needle.size();
        for(int i=0; i+k-1<haystack.size(); i++){
        	int j = 0;
        	while(j<k && j+i<haystack.size() && haystack[j+i] == needle[j])
        		j++;
        	if(j == needle.size())	return i;
        }
        return -1;
    }
};
