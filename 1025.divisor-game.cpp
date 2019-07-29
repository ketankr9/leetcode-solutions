/*
 * @lc app=leetcode id=1025 lang=cpp
 *
 * [1025] Divisor Game
 *
 * https://leetcode.com/problems/divisor-game/description/
 *
 * algorithms
 * Easy (64.12%)
 * Total Accepted:    17.2K
 * Total Submissions: 26.8K
 * Testcase Example:  '2'
 *
 * Alice and Bob take turns playing a game, with Alice starting first.
 * 
 * Initially, there is a number N on the chalkboard.  On each player's turn,
 * that player makes a move consisting of:
 * 
 * 
 * Choosing any x with 0 < x < N and N % x == 0.
 * Replacing the number N on the chalkboard with N - x.
 * 
 * 
 * Also, if a player cannot make a move, they lose the game.
 * 
 * Return True if and only if Alice wins the game, assuming both players play
 * optimally.
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: 2
 * Output: true
 * Explanation: Alice chooses 1, and Bob has no more moves.
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 3
 * Output: false
 * Explanation: Alice chooses 1, Bob chooses 1, and Alice has no more
 * moves.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= N <= 1000
 * 
 * 
 * 
 */
class Solution {
public:
    unordered_map<int, unordered_map<bool, bool>> dp;
    bool callme(int n, bool isx){
        if(n == 0)
            return !isx;
        
        if(dp.find(n)!=dp.end() && dp[n].find(isx)!=dp[n].end())
            return dp[n][isx];
        
        bool ans = isx?false:true;
        for(int x = 1; x<n; x++){
            if(n%x!=0)  continue;
            if(isx)
                ans |= callme(n-x, !isx);
            else
                ans &= callme(n-x, !isx);
        }
        dp[n][isx] = ans;
        return ans;
    }
    bool divisorGame(int N) {
        dp.clear();
        return callme(N, true);
    }
};
