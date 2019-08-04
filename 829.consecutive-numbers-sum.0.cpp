/*
 * @lc app=leetcode id=829 lang=cpp
 *
 * [829] Consecutive Numbers Sum
 *
 * https://leetcode.com/problems/consecutive-numbers-sum/description/
 *
 * algorithms
 * Hard (33.86%)
 * Total Accepted:    12.7K
 * Total Submissions: 37.6K
 * Testcase Example:  '5'
 *
 * Given a positive integer N, how many ways can we write it as a sum of
 * consecutive positive integers?
 * 
 * Example 1:
 * 
 * 
 * Input: 5
 * Output: 2
 * Explanation: 5 = 5 = 2 + 3
 * 
 * Example 2:
 * 
 * 
 * Input: 9
 * Output: 3
 * Explanation: 9 = 9 = 4 + 5 = 2 + 3 + 4
 * 
 * Example 3:
 * 
 * 
 * Input: 15
 * Output: 4
 * Explanation: 15 = 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
 * 
 * Note: 1 <= N <= 10 ^ 9.
 * 
 */
class Solution {
public:
    #define ll long long
    int consecutiveNumbersSum(int N) {
        while(N%2==0)
            N/=2;
        int cnt = 0;
        for(int i=1; i<=sqrt(N); i+=2){
            cnt += 2*(N%i==0) -(i*i==N?1:0);
        }
        return cnt;
    }
};
