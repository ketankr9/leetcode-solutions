/*
 * @lc app=leetcode id=434 lang=cpp
 *
 * [434] Number of Segments in a String
 *
 * https://leetcode.com/problems/number-of-segments-in-a-string/description/
 *
 * algorithms
 * Easy (36.56%)
 * Total Accepted:    53.8K
 * Total Submissions: 146.3K
 * Testcase Example:  '"Hello, my name is John"'
 *
 * Count the number of segments in a string, where a segment is defined to be a
 * contiguous sequence of non-space characters.
 * 
 * Please note that the string does not contain any non-printable characters.
 * 
 * Example:
 * 
 * Input: "Hello, my name is John"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int countSegments(string s) {
        // if(s.size() == 0)
        //     return 0;
        // all space
        int i = 0;
        int cnt = 0;
        while(i < (int)s.size()){
            while(i < (int)s.size() && s[i] == ' ')
                i++;
            int flag = 0;
            while(i < (int)s.size() && s[i] != ' '){
                flag = 1;
                i++;
            }
            cnt += flag;
        }
        return cnt;
    }
};
