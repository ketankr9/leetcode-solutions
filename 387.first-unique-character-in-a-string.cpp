/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 *
 * https://leetcode.com/problems/first-unique-character-in-a-string/description/
 *
 * algorithms
 * Easy (50.31%)
 * Likes:    1071
 * Dislikes: 81
 * Total Accepted:    288K
 * Total Submissions: 572.1K
 * Testcase Example:  '"leetcode"'
 *
 * 
 * Given a string, find the first non-repeating character in it and return it's
 * index. If it doesn't exist, return -1.
 * 
 * Examples:
 * 
 * s = "leetcode"
 * return 0.
 * 
 * s = "loveleetcode",
 * return 2.
 * 
 * 
 * 
 * 
 * Note: You may assume the string contain only lowercase letters.
 * 
 */
class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26];
        fill_n(arr, 26, 0);
        // for(int i=0; i<26; i++)
        //     arr[i] = false;
        for(int i=0; i<(int)s.size(); i++)
            arr[s[i]-'a']++;
        for(int i=0; i<(int)s.size(); i++)
            if(arr[s[i]-'a'] == 1)
                return i;
        return -1;
    }
};

