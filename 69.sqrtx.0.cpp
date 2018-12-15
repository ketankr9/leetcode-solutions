/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (29.92%)
 * Total Accepted:    299.4K
 * Total Submissions: 999.7K
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 *
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 *
 * Example 1:
 *
 *
 * Input: 4
 * Output: 2
 *
 *
 * Example 2:
 *
 *
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since
 * the decimal part is truncated, 2 is returned.
 *
 *
 */
class Solution {
public:
    int mySqrt(int x) {
      if(x < 2)  return x;
      double x0 = x/2;
      double x1;
      // x1 = x0 - f(x0)/f'(x0)
      // f(x0) = x0**2 - x
      // f'(x0) = 2x0

      while(true){
        // x1 = x0 - (x0*x0-x)/(2*x0);
        x1 = (x0 + x/x0)/2;
        x0 = x1;
        // cout<<x0<<" ";
        long t = x0;
        if(t*t <= (long)x && (long)x < (t+1)*(t+1)) return t;
      }
    }
};
