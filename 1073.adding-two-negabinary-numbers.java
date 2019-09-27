/*
 * @lc app=leetcode id=1073 lang=java
 *
 * [1073] Adding Two Negabinary Numbers
 *
 * https://leetcode.com/problems/adding-two-negabinary-numbers/description/
 *
 * algorithms
 * Medium (31.73%)
 * Total Accepted:    4K
 * Total Submissions: 12.7K
 * Testcase Example:  '[1,1,1,1,1]\n[1,0,1]'
 *
 * Given two numbers arr1 and arr2 in base -2, return the result of adding them
 * together.
 * 
 * Each number is given in array format:  as an array of 0s and 1s, from most
 * significant bit to least significant bit.  For example, arr = [1,1,0,1]
 * represents the number (-2)^3 + (-2)^2 + (-2)^0 = -3.  A number arr in array
 * format is also guaranteed to have no leading zeros: either arr == [0] or
 * arr[0] == 1.
 * 
 * Return the result of adding arr1 and arr2 in the same format: as an array of
 * 0s and 1s with no leading zeros.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: arr1 = [1,1,1,1,1], arr2 = [1,0,1]
 * Output: [1,0,0,0,0]
 * Explanation: arr1 represents 11, arr2 represents 5, the output represents
 * 16.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= arr1.length <= 1000
 * 1 <= arr2.length <= 1000
 * arr1 and arr2 have no leading zeros
 * arr1[i] is 0 or 1
 * arr2[i] is 0 or 1
 * 
 */
class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        Stack<Integer> st = new Stack<>();
        int carry = 0;
        int i = arr1.length-1;
        int j = arr2.length-1;
    	while(i>=0 || j>=0 || carry!=0){
    		int last = carry;
    		if(i>=0)
    			last += arr1[i--];
    		if(j>=0)
    			last += arr2[j--];
    		st.push(last&1);
    		carry = -(last>>1);
    	}
    	while(st.size() > 1 && st.peek() == 0)
    		st.pop();
    	int[] ans = new int[st.size()];
    	i = 0;
    	while(!st.empty()){
    		ans[i++] = st.peek();
    		st.pop();
    	}
    	return ans;
    }
}
