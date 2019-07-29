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
    unordered_map<int, unordered_map<int, int>> mm;
    int callme(int i, int state, vector<int>& prices){
      if(i == (int)prices.size())
        return 0;

      if(mm.find(i)!=mm.end() && mm[i].find(state)!=mm[i].end())
        return mm[i][state];

      if(i == (int)prices.size()-1)
        if(state == 2)
          return prices[i] + callme(i+1, 3, prices);
        else
          return 0;

        int ans;
        if(state == 1)
          ans = max(callme(i+1, 1, prices), - prices[i]+callme(i+1, 2, prices));
        else if(state == 2)
          ans = max(callme(i+1, 2, prices), +prices[i] + callme(i+1, 3, prices));
        else if(state == 3)
          ans = callme(i+1, 1, prices);
        
        mm[i][state] = ans;
        return ans;
    }

    int maxProfit(vector<int>& prices) {
      mm.clear();
      return callme(0, 1, prices);
    }
};
