/*
 * @lc app=leetcode id=747 lang=cpp
 *
 * [747] Largest Number At Least Twice of Others
 *
 * https://leetcode.com/problems/largest-number-at-least-twice-of-others/description/
 *
 * algorithms
 * Easy (40.72%)
 * Likes:    207
 * Dislikes: 423
 * Total Accepted:    54.8K
 * Total Submissions: 134.6K
 * Testcase Example:  '[0,0,0,1]'
 *
 * In a given integer array nums, there is always exactly one largest element.
 * 
 * Find whether the largest element in the array is at least twice as much as
 * every other number in the array.
 * 
 * If it is, return the index of the largest element, otherwise return -1.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [3, 6, 1, 0]
 * Output: 1
 * Explanation: 6 is the largest integer, and for every other number in the
 * array x,
 * 6 is more than twice as big as x.  The index of value 6 is 1, so we return
 * 1.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [1, 2, 3, 4]
 * Output: -1
 * Explanation: 4 isn't at least as big as twice the value of 3, so we return
 * -1.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * nums will have a length in the range [1, 50].
 * Every nums[i] will be an integer in the range [0, 99].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max1 = -1;
        int max2 = -1;
        int idx = -1;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] > max1){
                max2 = max1;
                max1 = nums[i];
                idx = i;
            }else if(nums[i] > max2){
                max2 = nums[i];
            }
        }
        if(max2*2>max1)   return -1;
        return idx;
    }
};

