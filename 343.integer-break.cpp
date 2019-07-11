/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (48.07%)
 * Likes:    612
 * Dislikes: 172
 * Total Accepted:    82.1K
 * Total Submissions: 170.7K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1);
        for(int i=0; i<n;i++)
            dp[i]=i;
        for(int k=2; k<n; k++){
            for(int i=1; i<=k/2; i++)
                dp[k] = max(dp[k], dp[i]*dp[k-i]);
        }
        dp[n] = n-1;
        for(int i=1; i<=n/2; i++)
            dp[n] = max(dp[n], dp[i]*dp[n-i]);
        return dp[n];
    }
};

