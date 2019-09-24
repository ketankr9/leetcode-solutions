/*
 * @lc app=leetcode id=907 lang=cpp
 *
 * [907] Sum of Subarray Minimums
 *
 * https://leetcode.com/problems/sum-of-subarray-minimums/description/
 *
 * algorithms
 * Medium (29.16%)
 * Total Accepted:    14.5K
 * Total Submissions: 49.7K
 * Testcase Example:  '[3,1,2,4]'
 *
 * Given an array of integers A, find the sum of min(B), where B ranges over
 * every (contiguous) subarray of A.
 * 
 * Since the answer may be large, return the answer modulo 10^9 + 7.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [3,1,2,4]
 * Output: 17
 * Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2],
 * [1,2,4], [3,1,2,4]. 
 * Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= A.length <= 30000
 * 1 <= A[i] <= 30000
 * 
 * 
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
    	long long ans = 0, M = 1e9+7;
    	int n = A.size();
    	vector<int> left;

    	stack<int> st;
    	for(int i=0; i<n; i++){
    		while(!st.empty() && A[st.top()] > A[i])
    			st.pop();
    		left.push_back(st.empty()?-1:st.top());
    		st.push(i);
    	}

    	stack<int> empty; swap(empty, st);
    	for(int i=n-1; i>=0; i--){
    		while(!st.empty() && A[st.top()] >= A[i])
    			st.pop();
    		int right = st.empty()?n:st.top();
    		ans  = (ans + (long long)A[i]*(i-left[i])*(right-i))%M;
    		st.push(i);
    	}    	
    	return ans;
    }
};
