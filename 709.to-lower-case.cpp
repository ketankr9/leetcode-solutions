/*
 * @lc app=leetcode id=709 lang=cpp
 *
 * [709] To Lower Case
 *
 * https://leetcode.com/problems/to-lower-case/description/
 *
 * algorithms
 * Easy (76.21%)
 * Total Accepted:    78.7K
 * Total Submissions: 103.1K
 * Testcase Example:  '"Hello"'
 *
 * Implement function ToLowerCase() that has a string parameter str, and
 * returns the same string in lowercase.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "Hello"
 * Output: "hello"
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "here"
 * Output: "here"
 * 
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "LOVELY"
 * Output: "lovely"
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0;i<(int)str.size();i++){
            if(str[i] <= 'Z' && str[i] >= 'A')
                str[i] = 'a' + str[i]-'A';
        }
        return str;
    }
};
