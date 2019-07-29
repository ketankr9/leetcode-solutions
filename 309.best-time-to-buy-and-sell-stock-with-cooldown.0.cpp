/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/description/
 *
 * algorithms
 * Medium (44.41%)
 * Total Accepted:    97.4K
 * Total Submissions: 219.2K
 * Testcase Example:  '[1,2,3,0,2]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 *
 * Design an algorithm to find the maximum profit. You may complete as many
 * transactions as you like (ie, buy one and sell one share of the stock
 * multiple times) with the following restrictions:
 *
 *
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1
 * day)
 *
 *
 * Example:
 *
 *
 * Input: [1,2,3,0,2]
 * Output: 3
 * Explanation: transactions = [buy, sell, cooldown, buy, sell]
 *
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 0)  return 0;
        int dp[n][3];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = INT_MIN;
        for(int i=1; i<n; i++){
          //state 0
          dp[i][0] = max(dp[i-1][0], dp[i-1][2]);
          dp[i][1] = max(dp[i-1][1], - prices[i]+dp[i-1][0]);
          dp[i][2] = prices[i] + dp[i-1][1];
        }
        return max(dp[n-1][2], dp[n-1][0]);
    }
};
