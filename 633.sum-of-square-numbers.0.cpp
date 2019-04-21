/*
 * @lc app=leetcode id=633 lang=cpp
 *
 * [633] Sum of Square Numbers
 *
 * https://leetcode.com/problems/sum-of-square-numbers/description/
 *
 * algorithms
 * Easy (32.79%)
 * Total Accepted:    41.9K
 * Total Submissions: 128K
 * Testcase Example:  '5'
 *
 * Given a non-negative integer c, your task is to decide whether there're two
 * integers a and b such that a2 + b2 = c.
 * 
 * Example 1:
 * 
 * 
 * Input: 5
 * Output: True
 * Explanation: 1 * 1 + 2 * 2 = 5
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: False
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0; i<=sqrt(c);i++){
            double temp = c - i*i;
            int tempInt = (int)sqrt(temp);
            if(temp == tempInt*tempInt)
                return true;
        }
        return false;
    }
};
