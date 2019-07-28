/*
 * @lc app=leetcode id=292 lang=cpp
 *
 * [292] Nim Game
 *
 * https://leetcode.com/problems/nim-game/description/
 *
 * algorithms
 * Easy (55.75%)
 * Total Accepted:    188.1K
 * Total Submissions: 337.4K
 * Testcase Example:  '4'
 *
 * You are playing the following Nim Game with your friend: There is a heap of
 * stones on the table, each time one of you take turns to remove 1 to 3
 * stones. The one who removes the last stone will be the winner. You will take
 * the first turn to remove the stones.
 * 
 * Both of you are very clever and have optimal strategies for the game. Write
 * a function to determine whether you can win the game given the number of
 * stones in the heap.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: false 
 * Explanation: If there are 4 stones in the heap, then you will never win the
 * game;
 * No matter 1, 2, or 3 stones you remove, the last stone will always
 * be 
 * removed by your friend.
 */
class Solution {
public:
    bool canWinNim(int n) {
        // bool dp[n+1][2];
        // dp[3][1] = dp[2][1] = dp[1][1] = true;
        // dp[3][0] = dp[2][0] = dp[1][0] = false;

        // for(int i=4; i<=n; i++){
        //     dp[i][1] = dp[i-1][0] | dp[i-2][0] | dp[i-3][0];
        //     dp[i][0] = dp[i-1][1] & dp[i-2][1] & dp[i-3][1];
        // }
        // return dp[n][1];
        return n%4!=0;
    }
};
