/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * https://leetcode.com/problems/valid-anagram/description/
 *
 * algorithms
 * Easy (52.72%)
 * Likes:    760
 * Dislikes: 114
 * Total Accepted:    361.3K
 * Total Submissions: 684.7K
 * Testcase Example:  '"anagram"\n"nagaram"'
 *
 * Given two strings s and t , write a function to determine if t is an anagram
 * of s.
 * 
 * Example 1:
 * 
 * 
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * 
 * Note:
 * You may assume the string contains only lowercase alphabets.
 * 
 * Follow up:
 * What if the inputs contain unicode characters? How would you adapt your
 * solution to such case?
 * 
 */
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mm;
        
        if(s.size() != t.size())
            return false;
        
        for(auto e: s)
            mm[e]++;
        for(auto e: t){
            mm[e]--;
            if(mm[e]<0)
                return false;
        }
        return true;
    }
};

