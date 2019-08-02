/*
 * @lc app=leetcode id=287 lang=cpp
 *
 * [287] Find the Duplicate Number
 *
 * https://leetcode.com/problems/find-the-duplicate-number/description/
 *
 * algorithms
 * Medium (50.39%)
 * Total Accepted:    205.6K
 * Total Submissions: 407.7K
 * Testcase Example:  '[1,3,4,2,2]'
 *
 * Given an array nums containing n + 1 integers where each integer is between
 * 1 and n (inclusive), prove that at least one duplicate number must exist.
 * Assume that there is only one duplicate number, find the duplicate one.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,4,2,2]
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,3,4,2]
 * Output: 3
 * 
 * Note:
 * 
 * 
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated
 * more than once.
 * 
 * 
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0; i<n; i++)
            for(int j=i+1; j<n; j++)
                if(nums[i] == nums[j])  return nums[i];

        return 0;
    }
};
