/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (26.61%)
 * Total Accepted:    141K
 * Total Submissions: 529.6K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 *
 * Each element in the array represents your maximum jump length at that
 * position.
 *
 * Your goal is to reach the last index in the minimum number of jumps.
 *
 * Example:
 *
 *
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 *
 * Note:
 *
 * You can assume that you can always reach the last index.
 *
 */
class Solution {
public:
    // int jumpFrom(int start, std::vector<int>& nums, int *memo){
    //   if(start >= (int)nums.size()-1)
    //     return 0;
    //   if(memo[start] != -1)
    //     return memo[start];
    //   if(start + nums[start] >= (int)nums.size()-1)
    //     return 1;
    //
    //   int minn = INT_MAX-1;
    //   for(int i=start+1; i<=start + nums[start] && i<=(int)nums.size();i++){
    //     minn = min(minn, jumpFrom(i, nums, memo));
    //     // if(minn == )
    //   }
    //   memo[start] = 1 + minn;
    //   return memo[start];
    // }
    int jump(vector<int>& nums) {
        // int N = nums.size();
        // if(N == 0)  return 0;
        // int memo[N]; fill_n(memo, N, -1);
        // return jumpFrom(0, nums, memo);
        int N = nums.size();
        if(N==0 || N==1) return 0;
        int start = 0, end = 0 + nums[0];
        int jump = 1;
        while(end < N-1){
          jump++;
          int maxx = start;
          for(int i=start+1; i<=end;i++)
            maxx = max(maxx, i+nums[i]);
          start = end;
          end = maxx;
        }
        return jump;
    }
};
