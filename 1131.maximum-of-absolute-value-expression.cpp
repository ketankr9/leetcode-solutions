/*
 * @lc app=leetcode id=1131 lang=cpp
 *
 * [1131] Maximum of Absolute Value Expression
 *
 * https://leetcode.com/problems/maximum-of-absolute-value-expression/description/
 *
 * algorithms
 * Medium (52.11%)
 * Total Accepted:    3.5K
 * Total Submissions: 6.7K
 * Testcase Example:  '[1,2,3,4]\n[-1,4,5,6]'
 *
 * Given two arrays of integers with equal lengths, return the maximum value
 * of:
 * 
 * |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
 * 
 * where the maximum is taken over all 0 <= i, j < arr1.length.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr1 = [1,2,3,4], arr2 = [-1,4,5,6]
 * Output: 13
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: arr1 = [1,-2,-5,0,10], arr2 = [0,-2,-1,-7,-4]
 * Output: 20
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 2 <= arr1.length == arr2.length <= 40000
 * -10^6 <= arr1[i], arr2[i] <= 10^6
 * 
 * 
 */
class Solution {
public:
	int callme(vector<int>& arr1, vector<int>& arr2, int a, int b){
		int minn = a*arr1[0]+b*arr2[0];
		int ans = INT_MIN;
		for(int i=1; i<arr1.size(); i++){
			int cur = a*arr1[i]+b*arr2[i]+i;
			ans = max(ans, cur-minn);
			minn = min(minn, cur);
		}
		return ans;
	}
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
    	int ans = INT_MIN;
    	for(int x: {1, -1})
    		for(int y: {1, -1})
    			ans = max(ans, callme(arr1, arr2, x, y));
    	return ans;
    }
};