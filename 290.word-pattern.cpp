/*
 * @lc app=leetcode id=290 lang=cpp
 *
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (35.55%)
 * Total Accepted:    153.8K
 * Total Submissions: 432.7K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * 
 * Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Example 1:
 * 
 * 
 * Input: pattern = "abba", str = "dog cat cat dog"
 * Output: true
 * 
 * Example 2:
 * 
 * 
 * Input:pattern = "abba", str = "dog cat cat fish"
 * Output: false
 * 
 * Example 3:
 * 
 * 
 * Input: pattern = "aaaa", str = "dog cat cat dog"
 * Output: false
 * 
 * Example 4:
 * 
 * 
 * Input: pattern = "abba", str = "dog dog dog dog"
 * Output: false
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters that may be separated by a single space.
 * 
 */
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> mm;
        unordered_set<string> ss;
        int j = 0;
        for(int i=0; i<pattern.size(); i++){
        	string tmp = "";
        	while(j<str.size() && str[j]!=' ')
        		tmp += str[j++];
        	j++; // remove space
        	if(tmp == "")	return false;
        	if(mm.find(pattern[i]) == mm.end()){
        		mm.insert({pattern[i], tmp});
        		if(ss.count(tmp)!=0)	return false;
        		ss.insert(tmp);
        	}else if(mm[pattern[i]] != tmp){
        		return false;
        	}
        }
        return j >= str.size();
    }
};
