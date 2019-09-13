/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 *
 * https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (43.53%)
 * Total Accepted:    317.1K
 * Total Submissions: 728.4K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
 * 
 * Find the minimum element.
 * 
 * You may assume no duplicate exists in the array.
 * 
 * Example 1:
 * 
 * 
 * Input: [3,4,5,1,2] 
 * Output: 1
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [4,5,6,7,0,1,2]
 * Output: 0
 * 
 * 
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
    	if(nums.empty())	return -1;
        int low = 0, high = (int)nums.size()-1;
        while(low<high){
        	int mid = low + (high-low)/2;
        	if(nums[low] < nums[high]){ // whole array is sorted
        		return nums[low];
        	}else if(nums[low] < nums[mid]){ // left is sorted
        		low = mid+1;
        	}else{ // right is sorted
        		high = mid;
        	}
        }
        if(low+1<nums.size() && nums[low+1] < nums[low])
        	return nums[low+1];
        return nums[low];
    }
};
