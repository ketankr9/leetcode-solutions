/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (39.69%)
 * Total Accepted:    175.4K
 * Total Submissions: 441.9K
 * Testcase Example:  '[10,9,2,5,3,7,101,18]'
 *
 * Given an unsorted array of integers, find the length of longest increasing
 * subsequence.
 * 
 * Example:
 * 
 * 
 * Input: [10,9,2,5,3,7,101,18]
 * Output: 4 
 * Explanation: The longest increasing subsequence is [2,3,7,101], therefore
 * the length is 4. 
 * 
 * Note: 
 * 
 * 
 * There may be more than one LIS combination, it is only necessary for you to
 * return the length.
 * Your algorithm should run in O(n2) complexity.
 * 
 * 
 * Follow up: Could you improve it to O(n log n) time complexity?
 * 
 */
class Solution {
public:
    int callme(int start, vector<int>& nums, int *memo){
        int maxx = 1;
        if(memo[start] != -1)
            return memo[start];
        for(int i=start+1; i<(int)nums.size();i++){
            if(nums[start] < nums[i])
                maxx = max(maxx, 1 + callme(i, nums, memo));
        }
        memo[start] = maxx;
        return maxx;
    }

    int lengthOfLIS(vector<int>& nums) {
        int maxx = 0;
        int N = (int)nums.size();
        if (N == 0)
            return {};
        int memo[N];
        fill_n(memo,N,-1);
        for(int i=0;i<N;i++)
            maxx = max(maxx,callme(i, nums, memo));
        return maxx;
    }
};
