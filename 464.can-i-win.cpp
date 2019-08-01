/*
 * @lc app=leetcode id=464 lang=cpp
 *
 * [464] Can I Win
 *
 * https://leetcode.com/problems/can-i-win/description/
 *
 * algorithms
 * Medium (27.58%)
 * Total Accepted:    38.1K
 * Total Submissions: 138K
 * Testcase Example:  '10\n11'
 *
 * In the "100 game," two players take turns adding, to a running total, any
 * integer from 1..10. The player who first causes the running total to reach
 * or exceed 100 wins.
 *
 * What if we change the game so that players cannot re-use integers?
 *
 * For example, two players might take turns drawing from a common pool of
 * numbers of 1..15 without replacement until they reach a total >= 100.
 *
 * Given an integer maxChoosableInteger and another integer desiredTotal,
 * determine if the first player to move can force a win, assuming both players
 * play optimally.
 *
 * You can always assume that maxChoosableInteger will not be larger than 20
 * and desiredTotal will not be larger than 300.
 *
 *
 * Example
 *
 * Input:
 * maxChoosableInteger = 10
 * desiredTotal = 11
 *
 * Output:
 * false
 *
 * Explanation:
 * No matter which integer the first player choose, the first player will lose.
 * The first player can choose an integer from 1 up to 10.
 * If the first player choose 1, the second player can only choose integers
 * from 2 up to 10.
 * The second player will win by choosing 10 and get a total = 11, which is >=
 * desiredTotal.
 * Same with other integers chosen by the first player, the second player will
 * always win.
 *
 *
 */
class Solution {
public:
    bool callme(int x, int k, int n, int target, bool isx){
      if(x>=target)
        return !isx;

      if(dp[k] != -1)
        return dp[k];

      for(int i=0; i<n; i++){
        if(k & (1<<i))  continue;
        bool tmp = callme(x+i+1, k | (1<<i), n, target, isx^true);
        if(isx && tmp){
          dp[k] = 1;
          return true;
        }else if(!isx && !tmp){
          dp[k] = 0;
          return false;
        }
      }
      dp[k] = isx?false:true;
      return dp[k];
    }

    vector<int> dp;
    bool canIWin(int mC, int dT) {
        if(dT == 0) return true;
        if(mC*(mC+1) < dT*2)
          return false;
        dp = vector<int>((1<<mC)+1, -1);
        return callme(0, 0, mC,dT, true);
    }
};
