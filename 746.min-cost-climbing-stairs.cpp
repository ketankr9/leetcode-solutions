/*
 * @lc app=leetcode id=746 lang=cpp
 *
 * [746] Min Cost Climbing Stairs
 *
 * https://leetcode.com/problems/min-cost-climbing-stairs/description/
 *
 * algorithms
 * Easy (47.76%)
 * Total Accepted:    89.8K
 * Total Submissions: 188.1K
 * Testcase Example:  '[0,0,0,0]'
 *
 * 
 * On a staircase, the i-th step has some non-negative cost cost[i] assigned (0
 * indexed).
 * 
 * Once you pay the cost, you can either climb one or two steps. You need to
 * find minimum cost to reach the top of the floor, and you can either start
 * from the step with index 0, or the step with index 1.
 * 
 * 
 * Example 1:
 * 
 * Input: cost = [10, 15, 20]
 * Output: 15
 * Explanation: Cheapest is start on cost[1], pay that cost and go to the
 * top.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
 * Output: 6
 * Explanation: Cheapest is start on cost[0], and only step on 1s, skipping
 * cost[3].
 * 
 * 
 * 
 * Note:
 * 
 * cost will have a length in the range [2, 1000].
 * Every cost[i] will be an integer in the range [0, 999].
 * 
 * 
 */
class Solution {
public:
    unordered_map<int, int> dp;
    int callme(int i, vector<int>& cost){
        if(i >= (int)cost.size())   return 0;
        if(dp.find(i)!=dp.end())    return dp[i];

        dp[i] = cost[i] + min(callme(i+1, cost), callme(i+2, cost));
        return dp[i];
    }

    int minCostClimbingStairs(vector<int>& cost) {
        dp.clear();
        return min(callme(0, cost), callme(1, cost));    
    }
};
