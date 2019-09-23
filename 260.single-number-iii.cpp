/*
 * @lc app=leetcode id=260 lang=cpp
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
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto const& c: nums)
        	x^=c;
        int b = 0;
        while( ((x>>b)&1) == 0 )
        	b++;
        int left = 0, right = 0;
        for(int i=0; i<nums.size(); i++){
        	if((1<<b) & nums[i])
        		left^=nums[i];
        	else
        		right^=nums[i];
        }

        return {left, right};
    }
};
