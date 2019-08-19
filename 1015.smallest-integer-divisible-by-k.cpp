/*
 * @lc app=leetcode id=1015 lang=cpp
 *
 * [1015] Smallest Integer Divisible by K
 *
 * https://leetcode.com/problems/smallest-integer-divisible-by-k/description/
 *
 * algorithms
 * Medium (29.33%)
 * Total Accepted:    6.4K
 * Total Submissions: 21.9K
 * Testcase Example:  '1'
 *
 * Given a positive integer K, you need find the smallest positive integer N
 * such that N is divisible by K, and N only contains the digit 1.
 * 
 * Return the length of N.  If there is no such N, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 1
 * Output: 1
 * Explanation: The smallest answer is N = 1, which has length 1.
 * 
 * Example 2:
 * 
 * 
 * Input: 2
 * Output: -1
 * Explanation: There is no such positive integer N divisible by 2.
 * 
 * Example 3:
 * 
 * 
 * Input: 3
 * Output: 3
 * Explanation: The smallest answer is N = 111, which has length 3.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= K <= 10^5
 * 
 */
class Solution {
public:
    int smallestRepunitDivByK(int K) {
        if(K%2==0)  return -1;

        bool flag  = false;
        for(int i=1; i<=9; i++)
            if((K*i)%10 == 1)   flag = true;
        if(!flag)   return -1;

        int prev = 0;
        for(int i=0; i<=INT_MAX; i++){
            prev = (prev*10+1)%K;
            if(prev == 0) return i+1;
        }
        return -1;
    }
};