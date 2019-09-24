/*
 * @lc app=leetcode id=1043 lang=cpp
 *
 * [1043] Partition Array for Maximum Sum
 *
 * https://leetcode.com/problems/partition-array-for-maximum-sum/description/
 *
 * algorithms
 * Medium (62.73%)
 * Total Accepted:    8.5K
 * Total Submissions: 13.6K
 * Testcase Example:  '[1,15,7,9,2,5,10]\n3'
 *
 * Given an integer array A, you partition the array into (contiguous)
 * subarrays of length at most K.  After partitioning, each subarray has their
 * values changed to become the maximum value of that subarray.
 * 
 * Return the largest sum of the given array after partitioning.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: A = [1,15,7,9,2,5,10], K = 3
 * Output: 84
 * Explanation: A becomes [15,15,15,9,10,10,10]
 * 
 * 
 * 
 * Note:
 * 
 * 
 * 1 <= K <= A.length <= 500
 * 0 <= A[i] <= 10^6
 * 
 * 
 */
class Solution {
public:
	vector<int> dp;
	int callme(vector<vector<int>>& maxx, int n, int K){
		if(n == -1)	return 0;
		if(dp[n] != -1)
			return dp[n];
		int ret = 0;
		for(int i = max(0, n-K+1); i<=n; i++)
			ret = max(ret, callme(maxx, i-1, K) + maxx[i][n]*(n-i+1));
		return dp[n] = ret;
	}
    int maxSumAfterPartitioning(vector<int>& A, int K) {
    	int n = A.size();
    	dp.resize(n, -1);

    	vector<vector<int>> maxx(n+1, vector<int>(n+1));
    	for(int i=0; i+1<n; i++)
    		maxx[i][i] = A[i], maxx[i][i+1] = max(A[i], A[i+1]);
    	maxx[n-1][n-1] = A[n-1];

    	for(int k = 2; k < K; k++)
    		for(int i = 0; i+k < n; i++)
    			maxx[i][i+k] = max({A[i], maxx[i+1][i+k-1], A[i+k]});
    	
    	return callme(maxx, n-1, K);
    }
};
