/*
 * @lc app=leetcode id=456 lang=cpp
 *
 * [456] 132 Pattern
 *
 * https://leetcode.com/problems/132-pattern/description/
 *
 * algorithms
 * Medium (27.54%)
 * Total Accepted:    30.8K
 * Total Submissions: 111.8K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 
 * Given a sequence of n integers a1, a2, ..., an, a 132 pattern is a
 * subsequence ai, aj, ak such
 * that i < j < k and ai < ak < aj. Design an algorithm that takes a list of n
 * numbers as input and checks whether there is a 132 pattern in the list.
 * 
 * Note: n will be less than 15,000.
 * 
 * Example 1:
 * 
 * Input: [1, 2, 3, 4]
 * 
 * Output: False
 * 
 * Explanation: There is no 132 pattern in the sequence.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [3, 1, 4, 2]
 * 
 * Output: True
 * 
 * Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
 * 
 * 
 * 
 * Example 3:
 * 
 * Input: [-1, 3, 2, 0]
 * 
 * Output: True
 * 
 * Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1,
 * 3, 0] and [-1, 2, 0].
 * 
 * 
 */
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n<3)	return false;
        vector<int> leftmin(n);
        leftmin[0] = nums[0];
        for(int i=1; i<nums.size(); i++)
        	leftmin[i] = min(leftmin[i-1], nums[i]);
    	stack<int> st;
   		for(int i=n-1; i>=1; i--){
   			if(nums[i] <= leftmin[i-1])	continue;
   			while(!st.empty() && leftmin[i-1] >= st.top())
   				st.pop();
   			if(!st.empty() && leftmin[i-1] < nums[i] && nums[i] > st.top())	return true;
   			st.push(nums[i]);
   		}
   		return false;
    }
};
