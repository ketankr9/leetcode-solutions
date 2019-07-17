/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Easy (37.64%)
 * Likes:    1692
 * Dislikes: 132
 * Total Accepted:    132.9K
 * Total Submissions: 352.7K
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given a string s and a non-empty string p, find all the start indices of p's
 * anagrams in s.
 * 
 * Strings consists of lowercase English letters only and the length of both
 * strings s and p will not be larger than 20,100.
 * 
 * The order of output does not matter.
 * 
 * Example 1:
 * 
 * Input:
 * s: "cbaebabacd" p: "abc"
 * 
 * Output:
 * [0, 6]
 * 
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of
 * "abc".
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s: "abab" p: "ab"
 * 
 * Output:
 * [0, 1, 2]
 * 
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 */
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pcnt(26, 0);
        for(auto e: p)
            pcnt[e-'a']++;
        int start = 0;
        int np = p.size();
        int ns = s.size();
        vector<int> ans;

        while(start<ns){
            vector<int> tmp = pcnt;
            int i=start;
            int endd = start+np;
            for(; i<endd && i<ns; i++){
                tmp[s[i]-'a']--;
                if(tmp[s[i]-'a']<0){
                    while(start<ns && s[start]!=s[i])
                        start++;
                    break;
                }
            }
            if(i == endd)   ans.push_back(start);
            start++;
        }
        return ans;
    }
};

