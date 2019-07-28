/*
 * @lc app=leetcode id=877 lang=cpp
 *
 * [877] Stone Game
 *
 * https://leetcode.com/problems/stone-game/description/
 *
 * algorithms
 * Medium (61.64%)
 * Total Accepted:    29.4K
 * Total Submissions: 47.7K
 * Testcase Example:  '[5,3,4,5]'
 *
 * Alex and Lee play a game with piles of stones.  There are an even number of
 * piles arranged in a row, and each pile has a positive integer number of
 * stones piles[i].
 * 
 * The objective of the game is to end with the most stones.  The total number
 * of stones is odd, so there are no ties.
 * 
 * Alex and Lee take turns, with Alex starting first.  Each turn, a player
 * takes the entire pile of stones from either the beginning or the end of the
 * row.  This continues until there are no more piles left, at which point the
 * person with the most stones wins.
 * 
 * Assuming Alex and Lee play optimally, return True if and only if Alex wins
 * the game.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [5,3,4,5]
 * Output: true
 * Explanation: 
 * Alex starts first, and can only take the first 5 or the last 5.
 * Say he takes the first 5, so that the row becomes [3, 4, 5].
 * If Lee takes 3, then the board is [4, 5], and Alex takes 5 to win with 10
 * points.
 * If Lee takes the last 5, then the board is [3, 4], and Alex takes 4 to win
 * with 9 points.
 * This demonstrated that taking the first 5 was a winning move for Alex, so we
 * return true.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 2 <= piles.length <= 500
 * piles.length is even.
 * 1 <= piles[i] <= 500
 * sum(piles) is odd.
 * 
 */
class Solution {
public:
    unordered_map<int, unordered_map<int, int>> mm;
    int callme(int start, int end, vector<int>& piles, bool ismax){
        if(start>end)
            return 0;
        if(mm.find(start)!=mm.end() && mm[start].find(end)!=mm[start].end())
            return mm[start][end];

        int ans = 0;
        if(ismax)
            ans = max(piles[start]+callme(start+1, end, piles, false), piles[end]+callme(start, end-1, piles, false) );
        else
            ans = min(piles[start]+callme(start+1, end, piles, true), piles[end]+callme(start, end-1, piles, true) );

        mm[start][end] = ans;
        return ans;
    }
    bool stoneGame(vector<int>& piles) {
        mm.clear();
        int sum = 0;
        for(auto e: piles)
            sum += e;
        
        return callme(0, (int)piles.size()-1, piles, true) > sum/2;
    }
};
