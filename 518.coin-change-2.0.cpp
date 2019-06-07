/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (41.39%)
 * Total Accepted:    44.9K
 * Total Submissions: 105.1K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * <p>You are given coins of different denominations and a total amount of
 * money. Write a function to compute the number of combinations that make up
 * that amount. You may assume that you have infinite number of each kind of
 * coin.</p>
 * 
 * <ul>
 * </ul>
 * 
 * <p>&nbsp;</p>
 * 
 * <p><b>Example 1:</b></p>
 * 
 * <pre>
 * <b>Input:</b> amount = 5, coins = [1, 2, 5]
 * <b>Output:</b> 4
 * <b>Explanation:</b> there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * </pre>
 * 
 * <p><b>Example 2:</b></p>
 * 
 * <pre>
 * <b>Input:</b> amount = 3, coins = [2]
 * <b>Output:</b> 0
 * <b>Explanation:</b> the amount of 3 cannot be made up just with coins of 2.
 * </pre>
 * 
 * <p><b>Example 3:</b></p>
 * 
 * <pre>
 * <b>Input:</b> amount = 10, coins = [10] 
 * <b>Output:</b> 1
 * </pre>
 * 
 * <p>&nbsp;</p>
 * 
 * <p><b>Note:</b></p>
 * 
 * <p>You can assume that</p>
 * 
 * <ul>
 * <li>0 &lt;= amount &lt;= 5000</li>
 * <li>1 &lt;= coin &lt;= 5000</li>
 * <li>the number of coins is less than 500</li>
 * <li>the answer is guaranteed to fit into signed 32-bit integer</li>
 * </ul>
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> d(amount+1, 0);
        d[0] = 1;
        for(int i=0; i<n; i++){
            for(int amt=1; amt<amount+1; amt++){
                if(coins[i] <= amt)
                    d[amt] += d[amt-coins[i]];
            }
        }
        return d[amount];
    }
};
