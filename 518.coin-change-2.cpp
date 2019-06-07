/*
 * @lc app=leetcode id=518 lang=cpp
 *
 * [518] Coin Change 2
 *
 * https://leetcode.com/problems/coin-change-2/description/
 *
 * algorithms
 * Medium (41.39%)
 * Total Accepted:    41K
 * Total Submissions: 97.1K
 * Testcase Example:  '5\n[1,2,5]'
 *
 * You are given coins of different denominations and a total amount of money.
 * Write a function to compute the number of combinations that make up that
 * amount. You may assume that you have infinite number of each kind of
 * coin.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: amount = 5, coins = [1, 2, 5]
 * Output: 4
 * Explanation: there are four ways to make up the amount:
 * 5=5
 * 5=2+2+1
 * 5=2+1+1+1
 * 5=1+1+1+1+1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: amount = 3, coins = [2]
 * Output: 0
 * Explanation: the amount of 3 cannot be made up just with coins of 2.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: amount = 10, coins = [10] 
 * Output: 1
 * 
 * 
 * 
 * 
 * Note:
 * 
 * You can assume that
 * 
 * 
 * 0 <= amount <= 5000
 * 1 <= coin <= 5000
 * the number of coins is less than 500
 * the answer is guaranteed to fit into signed 32-bit integer
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> arr;
    int changeFrom(int start, vector<int> &coins, int amt_rem){
        if(amt_rem < 0)
            return 0;
        else if(amt_rem == 0)
            return 1;

        // auto it = arr.find(to_string(start)+":"+to_string(amt_rem));
        if(arr.find(start)!=arr.end() && arr[start].find(amt_rem)!=arr[start].end())
            return arr[start][amt_rem];
        
        int _count = 0;
        for(int i=start; i < (int)coins.size(); i++){
            _count += changeFrom(i, coins, amt_rem - coins[i]);
        }
        
        arr[start][amt_rem] = _count;

        return _count;

    }
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        arr.clear();

        int ans =  changeFrom(0, coins, amount);
        return ans;
    }
};
