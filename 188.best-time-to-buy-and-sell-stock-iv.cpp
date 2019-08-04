/*
 * @lc app=leetcode id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (26.59%)
 * Total Accepted:    92.5K
 * Total Submissions: 347.8K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most k
 * transactions.
 * 
 * Note:
 * You may not engage in multiple transactions at the same time (ie, you must
 * sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [2,4,1], k = 2
 * Output: 2
 * Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit
 * = 4-2 = 2.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,2,6,5,0,3], k = 2
 * Output: 7
 * Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit
 * = 6-2 = 4.
 * Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 =
 * 3.
 * 
 */
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        int n = prices.size();
        if(n == 0 || k == 0)  return 0;

        k = min(n/2, k);
        vector<int> b(k, INT_MIN);
        vector<int> s(k, 0);
        
        for(int i=0; i<n; i++){
            for(int j=k-1; j>=0; j--)
                b[j] = max(b[j], (!j?0:s[j-1])-prices[i]),
                s[j] = max(s[j], b[j]  +prices[i]);
        }
        int ans = 0;
        for(auto e: s)
            ans = max(ans, e);
        return ans;
    }
};
