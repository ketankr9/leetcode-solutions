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
    int binsearch(long start, long end, long value){
      if(start*start <= value && value < (start+1)*(start+1))
        return start;
      if(end*end <= value && value < (end+1)*(end+1))
          return end;
      long mid  = (start+end)/2;
      if(mid*mid <= value && value < (mid+1)*(mid+1))
        return mid;
      if(mid*mid < value){
        return binsearch(mid, end, value);
      }else{
        return binsearch(start, mid, value);
      }
    }

    int mySqrt(int x) {
        return binsearch(0, x, x);

    }
};
