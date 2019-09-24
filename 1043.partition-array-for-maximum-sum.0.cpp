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
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        int n = A.size();
        vector<int> dp(n+1);
        dp[0] = 0; dp[1] = A[0];
        for(int i = 1; i < n; i++){
        	int maxx = INT_MIN, ans = INT_MIN;
        	for(int j = i; i-j<K && j>=0; j--){
        		maxx = max(maxx, A[j]);
        		ans = max(ans, (i-j+1)*maxx+dp[j]);
        	}
        	dp[i+1] = ans;
        }
        return dp[n];
    }
};
