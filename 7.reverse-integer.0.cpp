/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 *
 * https://leetcode.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (24.69%)
 * Total Accepted:    541.1K
 * Total Submissions: 2.2M
 * Testcase Example:  '123'
 *
 * Given a 32-bit signed integer, reverse digits of an integer.
 *
 * Example 1:
 *
 *
 * Input: 123
 * Output: 321
 *
 *
 * Example 2:
 *
 *
 * Input: -123
 * Output: -321
 *
 *
 * Example 3:
 *
 *
 * Input: 120
 * Output: 21
 *
 *
 * Note:
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of
 * this problem, assume that your function returns 0 when the reversed integer
 * overflows.
 *
 */
class Solution {
public:
    int reverse(int x) {
        int neg = 1;
        if(x < 0) neg = -1;
        x*=neg;
        string st = to_string(x);
        for(int i=0;i<(int)st.size()/2;i++)
          swap(st[i], st[(int)st.size()-1-i]);
        try{
            return stoi(st)*neg;
        }catch(exception& e){
          return 0;
        }
    }
};
