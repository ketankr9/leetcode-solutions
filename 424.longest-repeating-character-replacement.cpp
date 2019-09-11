/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (44.56%)
 * Total Accepted:    34.6K
 * Total Submissions: 77.5K
 * Testcase Example:  '"ABAB"\n2'
 *
 * Given a string s that consists of only uppercase English letters, you can
 * perform at most k operations on that string.
 * 
 * In one operation, you can choose any character of the string and change it
 * to any other uppercase English character.
 * 
 * Find the length of the longest sub-string containing all repeating letters
 * you can get after performing the above operations.
 * 
 * Note:
 * Both the string's length and k will not exceed 104.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * s = "ABAB", k = 2
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the two 'A's with two 'B's or vice versa.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * s = "AABABBA", k = 1
 * 
 * Output:
 * 4
 * 
 * Explanation:
 * Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * 
 * 
 * 
 * 
 */
class Solution {
public:
	int callme(vector<int>& dp){
		int maxx = 0;
		for(int c=0; c<26; c++)
			maxx = max(maxx, dp[c]);
		return maxx;
	}
    int characterReplacement(string s, int K) {
    	vector<int> cnt(26, 0);
        int ans = 0, i = 0;
        for(int j = 0; j<s.size(); j++){
        	cnt[s[j]-'A']++;
        	while(i<j && (j-i+1-callme(cnt))>K)
        		--cnt[s[i++]-'A'];
        	ans = max(ans, j-i+1);
        }
        return ans;
    }
};
