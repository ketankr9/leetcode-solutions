/*
 * @lc app=leetcode id=467 lang=cpp
 *
 * [467] Unique Substrings in Wraparound String
 *
 * https://leetcode.com/problems/unique-substrings-in-wraparound-string/description/
 *
 * algorithms
 * Medium (34.23%)
 * Total Accepted:    19.2K
 * Total Submissions: 56K
 * Testcase Example:  '"a"'
 *
 * Consider the string s to be the infinite wraparound string of
 * "abcdefghijklmnopqrstuvwxyz", so s will look like this:
 * "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
 * 
 * Now we have another string p. Your job is to find out how many unique
 * non-empty substrings of p are present in s. In particular, your input is the
 * string p and you need to output the number of different non-empty substrings
 * of p in the string s.
 * 
 * Note: p consists of only lowercase English letters and the size of p might
 * be over 10000.
 * 
 * Example 1:
 * 
 * Input: "a"
 * Output: 1
 * 
 * Explanation: Only the substring "a" of string "a" is in the string s.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "cac"
 * Output: 2
 * Explanation: There are two substrings "a", "c" of string "cac" in the string
 * s.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: "zab"
 * Output: 6
 * Explanation: There are six substrings "z", "a", "b", "za", "ab", "zab" of
 * string "zab" in the string s.
 * 
 * 
 */
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> mm(26, 0);

        // int i = 0;
        int pos = 0;
        int n = p.size();
        while(pos < n){
            int i = pos;
            while(i+1<n && ((int)p[i+1]-'a') == ((int)p[i]-'a' + 1)%26)
                i++;
            while(pos<=i){
                mm[p[pos]-'a'] = max(mm[p[pos]-'a'], i-pos+1);
                pos++;
            }
            pos = i+1;
        }
        int ans = 0;
        for(int i=0; i<26; i++)
         ans += mm[i];
        return ans;
    }
};
