/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (30.60%)
 * Total Accepted:    213.3K
 * Total Submissions: 697K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Determine if you are able to reach the last index.
 *
 * Example 1:
 *
 *
 * Input: [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 *
 *
 * Example 2:
 *
 *
 * Input: [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its
 * maximum
 * jump length is 0, which makes it impossible to reach the last index.
 *
 * Follow up -->> [45] Jump Game II
 */
class Solution {
public:
    bool canJump(vector<int>& nums) {
      int N = nums.size();
      int maxReach = 0;
      int i=0;
      for(i=0;i<N && i<=maxReach && maxReach < N-1;i++)
        maxReach = max(maxReach, nums[i]+i);
      if(maxReach < N-1)
        return false;
      return true;
    }
};
