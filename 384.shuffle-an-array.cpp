/*
 * @lc app=leetcode id=384 lang=cpp
 *
 * [384] Shuffle an Array
 *
 * https://leetcode.com/problems/shuffle-an-array/description/
 *
 * algorithms
 * Medium (48.72%)
 * Total Accepted:    61K
 * Total Submissions: 125.1K
 * Testcase Example:  '["Solution","shuffle","reset","shuffle"]\n[[[1,2,3]],[],[],[]]'
 *
 * Shuffle a set of numbers without duplicates.
 *
 *
 * Example:
 *
 * // Init an array with set 1, 2, and 3.
 * int[] nums = {1,2,3};
 * Solution solution = new Solution(nums);
 *
 * // Shuffle the array [1,2,3] and return its result. Any permutation of
 * [1,2,3] must equally likely to be returned.
 * solution.shuffle();
 *
 * // Resets the array back to its original configuration [1,2,3].
 * solution.reset();
 *
 * // Returns the random shuffling of array [1,2,3].
 * solution.shuffle();
 *
 *
 */
class Solution {
public:
    vector<int> arr;
    vector<int> curr;
    int n;
    Solution(vector<int> nums) {
      arr = nums;
      curr = nums;
      n = nums.size();
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
      curr = arr;
      return curr;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
      if(n == 0)
        return curr;
      for(int i=0; i<n; i++){
        int k = rand()%n;
        swap(curr[k], curr[i]);
      }
      return curr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */
