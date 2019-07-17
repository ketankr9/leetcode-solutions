/*
 * @lc app=leetcode id=342 lang=cpp
 *
 * [342] Power of Four
 *
 * https://leetcode.com/problems/power-of-four/description/
 *
 * algorithms
 * Easy (40.49%)
 * Total Accepted:    117.8K
 * Total Submissions: 290.9K
 * Testcase Example:  '16'
 *
 * Given an integer (signed 32 bits), write a function to check whether it is a
 * power of 4.
 * 
 * Example 1:
 * 
 * 
 * Input: 16
 * Output: true
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 5
 * Output: false
 * 
 * 
 * Follow up: Could you solve it without loops/recursion?
 */
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num<=0)   return false;
        // num = pow(pow(2, 2), i) or pow(pow(2, i), 2)
        // which implies that sqrt(num) is a power of two
        // since x&-x is the greatest power of 2 dividing x -> imples here x&-x == x 
        int n = sqrt(num);
        return n*n == num && (n&-n)==n; 
    }
};
