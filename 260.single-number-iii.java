/*
 * @lc app=leetcode id=260 lang=java
 *
 * [260] Single Number III
 *
 * https://leetcode.com/problems/single-number-iii/description/
 *
 * algorithms
 * Medium (57.63%)
 * Total Accepted:    111.5K
 * Total Submissions: 193.3K
 * Testcase Example:  '[1,2,1,3,2,5]'
 *
 * Given an array of numbers nums, in which exactly two elements appear only
 * once and all the other elements appear exactly twice. Find the two elements
 * that appear only once.
 * 
 * Example:
 * 
 * 
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 * 
 * Note:
 * 
 * 
 * The order of the result is not important. So in the above example, [5, 3] is
 * also correct.
 * Your algorithm should run in linear runtime complexity. Could you implement
 * it using only constant space complexity?
 * 
 */
class Solution {
    public int[] singleNumber(int[] nums) {
        int[] ans = new int[2];
        int n = nums.length;
        HashSet<Integer> hs = new HashSet<>();
        for(int i=0; i<n; i++)
        	if(hs.contains(nums[i]))
        		hs.remove(nums[i]);
        	else
        		hs.add(nums[i]);
        Iterator<Integer> it = hs.iterator();
        ans[0] = it.next();
        ans[1] = it.next();
        return ans;
    }
}
