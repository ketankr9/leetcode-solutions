/*
 * @lc app=leetcode id=375 lang=cpp
 *
 * [375] Guess Number Higher or Lower II
 *
 * https://leetcode.com/problems/guess-number-higher-or-lower-ii/description/
 *
 * algorithms
 * Medium (38.17%)
 * Total Accepted:    46.3K
 * Total Submissions: 121.3K
 * Testcase Example:  '1'
 *
 * We are playing the Guess Game. The game is as follows:
 *
 * I pick a number from 1 to n. You have to guess which number I picked.
 *
 * Every time you guess wrong, I'll tell you whether the number I picked is
 * higher or lower.
 *
 * However, when you guess a particular number x, and you guess wrong, you pay
 * $x. You win the game when you guess the number I picked.
 *
 * Example:
 *
 *
 * n = 10, I pick 8.
 *
 * First round:  You guess 5, I tell you that it's higher. You pay $5.
 * Second round: You guess 7, I tell you that it's higher. You pay $7.
 * Third round:  You guess 9, I tell you that it's lower. You pay $9.
 *
 * Game over. 8 is the number I picked.
 *
 * You end up paying $5 + $7 + $9 = $21.
 *
 *
 * Given a particular n ≥ 1, find out how much money you need to have to
 * guarantee a win.
 */
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mm;
    int callme(int low, int high){
        if(low >= high)
          return 0;

        if(mm.find(low)!=mm.end() && mm[low].find(high)!=mm[low].end())
          return mm[low][high];

        int ans = INT_MAX;
        for(int x=low; x<=high; x++)
          ans = min(ans, x+max(callme(low, x-1), callme(x+1, high)));
        mm[low][high] = ans;
        return ans;
    }
    int getMoneyAmount(int n) {
      mm.clear();
      return callme(1, n);
    }
};
