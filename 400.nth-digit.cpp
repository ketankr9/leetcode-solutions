/*
 * @lc app=leetcode id=400 lang=cpp
 *
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Medium (30.67%)
 * Total Accepted:    50.8K
 * Total Submissions: 165.7K
 * Testcase Example:  '3'
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ... 
 * 
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 231).
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 3
 * 
 * Output:
 * 3
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 11
 * 
 * Output:
 * 0
 * 
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 * 
 * 
 */
class Solution {
public:
    int findNthDigit(int n) {
        int i = 1;
        while((long)n > (long)pow(10, i-1)*9*i){
        	n -= (int)pow(10, i-1)*9*i;
        	i++;
        }
        int div = (n-1)/i, rem = ((n-1)%i) + 1;
        int num = (int)pow(10, i-1)+div;
        int tmp = i-rem;
        while(tmp--)
        	num = num/10;
        return num%10;
    }
};
