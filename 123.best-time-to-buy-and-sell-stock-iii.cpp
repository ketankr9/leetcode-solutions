/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 *
 * https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
 *
 * algorithms
 * Hard (34.28%)
 * Total Accepted:    157.9K
 * Total Submissions: 460.6K
 * Testcase Example:  '[3,3,5,0,0,3,1,4]'
 *
 * Say you have an array for which the ith element is the price of a given
 * stock on day i.
 * 
 * Design an algorithm to find the maximum profit. You may complete at most two
 * transactions.
 * 
 * Note: You may not engage in multiple transactions at the same time (i.e.,
 * you must sell the stock before you buy again).
 * 
 * Example 1:
 * 
 * 
 * Input: [3,3,5,0,0,3,1,4]
 * Output: 6
 * Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit
 * = 3-0 = 3.
 * Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 =
 * 3.
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4,5]
 * Output: 4
 * Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit
 * = 5-1 = 4.
 * Note that you cannot buy on day 1, buy on day 2 and sell them later, as you
 * are
 * engaging multiple transactions at the same time. You must sell before buying
 * again.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,6,4,3,1]
 * Output: 0
 * Explanation: In this case, no transaction is done, i.e. max profit = 0.
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int max1, max2, lmax;
        // max1 = max2 = lmax = INT_MIN;
        // int n = prices.size();
        // if(n == 0)  return 0;
        // for(int i=n-1; i-1>=0; i--)
        //     prices[i] = prices[i]-prices[i-1];
        // prices[0] = 0;
        // int sum = 0;
        // for(int i=0; i<n; i++){
        //     if(sum+prices[i] > prices[i]){
        //         sum+=prices[i];
        //         lmax = max(lmax, sum);
        //     }else{
        //         sum = prices[i];
        //         cout<<" break "<<lmax<<" ";
        //         if(lmax > max1){
        //             max2 = max1;
        //             max1 = lmax;
        //         }else if(lmax > max2)
        //             max2 = lmax;
        //         lmax = sum;
        //     }
        // }
        // cout<<lmax<<" ";
        // if(lmax > max1){
        //     max2 = max1;
        //     max1 = lmax;
        // }else if(lmax > max2)
        //     max2 = lmax;

        // return max(0, max1) + max(0, max2);
        int n = prices.size();
        if(n == 0)  return 0;
        int diff[n];
        for(int i=n-1; i-1>=0; i--)
            diff[i] = prices[i]-prices[i-1];
        diff[0] = 0;
        int sum = 0;
        int buy1 = INT_MAX, sell1 = 0, buy2 = INT_MIN, sell2 = 0;
        for(int i=0; i<n; i++){
            buy2 = max(buy2, sell1-prices[i]);
            sell2 = max(sell2, buy2+prices[i]);
            
            buy1 = min(buy1, prices[i]);
            sell1 = max(sell1, prices[i]-buy1);
        }
        return max(sell1, sell2);
    }
};
