/*
 * @lc app=leetcode id=1186 lang=cpp
 *
 * [1186] Maximum Subarray Sum with One Deletion
 *
 * https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/description/
 *
 * algorithms
 * Medium (23.34%)
 * Total Accepted:    1.7K
 * Total Submissions: 7.4K
 * Testcase Example:  '[1,-2,0,3]'
 *
 * Given an array of integers, return the maximum sum for a non-empty subarray
 * (contiguous elements) with at most one element deletion. In other words, you
 * want to choose a subarray and optionally delete one element from it so that
 * there is still at least one element left and the sum of the remaining
 * elements is maximum possible.
 * 
 * Note that the subarray needs to be non-empty after deleting one element.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr = [1,-2,0,3]
 * Output: 4
 * Explanation: Because we can choose [1, -2, 0, 3] and drop -2, thus the
 * subarray [1, 0, 3] becomes the maximum value.
 * 
 * Example 2:
 * 
 * 
 * Input: arr = [1,-2,-2,3]
 * Output: 3
 * Explanation: We just choose [3] and it's the maximum sum.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: arr = [-1,-1,-1,-1]
 * Output: -1
 * Explanation: The final subarray needs to be non-empty. You can't choose [-1]
 * and delete -1 from it, then get an empty subarray to make the sum equals to
 * 0.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= arr.length <= 10^5
 * -10^4 <= arr[i] <= 10^4
 * 
 */
class Solution {
public:
    int maximumSum(vector<int>& arr) {
    	int n = arr.size();

        int gmax = arr[0]; // subarray max
        int max1 = arr[0]; // max elemment in the array

        int ignored = 0, notignored = 0;
        
        for(int i=0; i<arr.size(); i++){
        	// ignored -> two possibility explained below
        	//		- current element ignored  -> look for `notignored`
        	//		- some previous element was ignored -> look for `ignored+arr[i]`
        	ignored = max(notignored, ignored+arr[i]);

        	// none element ignored till now - typical kadane's
        	notignored = max(arr[i], arr[i]+notignored);
        	
        	gmax = max({gmax, ignored, notignored});
        	max1 = max(max1, arr[i]);
        }

        return max1<0?max1:gmax;
    }
};
