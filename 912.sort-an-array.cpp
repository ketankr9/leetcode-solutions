/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 *
 * https://leetcode.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (63.15%)
 * Total Accepted:    26.1K
 * Total Submissions: 41.3K
 * Testcase Example:  '[5,2,3,1]'
 *
 * Given an array of integers nums, sort the array in ascending order.
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [5,2,3,1]
 * Output: [1,2,3,5]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [5,1,1,2,0,0]
 * Output: [0,0,1,1,2,5]
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 10000
 * -50000 <= A[i] <= 50000
 * 
 * 
 */
class Solution {
public:
	void sort(int start, int end, vector<int>& nums){
		if(start>=end)	return ;

		int i = start+1, j = end;
		while(i<=j){
			if(nums[i] <= nums[start])
				i++;
			else if(nums[j] > nums[start])
				j--;
			else
				swap(nums[i++], nums[j--]);
		}
		
		swap(nums[start], nums[j]);
		sort(start, j-1, nums);
		sort(j+1, end, nums);
	}
    vector<int> sortArray(vector<int>& nums) {
        sort(0, nums.size()-1, nums);
        return nums;
    }
};
