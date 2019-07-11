/*
 * @lc app=leetcode id=503 lang=cpp
 *
 * [503] Next Greater Element II
 *
 * https://leetcode.com/problems/next-greater-element-ii/description/
 *
 * algorithms
 * Medium (51.38%)
 * Likes:    716
 * Dislikes: 44
 * Total Accepted:    53.1K
 * Total Submissions: 103.2K
 * Testcase Example:  '[1,2,1]'
 *
 * 
 * Given a circular array (the next element of the last element is the first
 * element of the array), print the Next Greater Number for every element. The
 * Next Greater Number of a number x is the first greater number to its
 * traversing-order next in the array, which means you could search circularly
 * to find its next greater number. If it doesn't exist, output -1 for this
 * number.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,2,1]
 * Output: [2,-1,2]
 * Explanation: The first 1's next greater number is 2; The number 2 can't find
 * next greater number; The second 1's next greater number needs to search
 * circularly, which is also 2.
 * 
 * 
 * 
 * Note:
 * The length of given array won't exceed 10000.
 * 
 */
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans;
        int n = nums.size();
        for(int i=n-1; i>=0; i--){
            // if(st.empty() || nums[i]<st.top())
                // st.push(nums[i]);
            // else if(nums[i] >= st.top()){
            while(!st.empty() && nums[i] >= st.top())
                st.pop();
            st.push(nums[i]);
            // }
        }
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[i] >= st.top())
                st.pop();
            if(st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(nums[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

