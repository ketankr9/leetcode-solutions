/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 *
 * https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
 *
 * algorithms
 * Medium (33.91%)
 * Total Accepted:    32.7K
 * Total Submissions: 96.3K
 * Testcase Example:  '[1,3,5,4,7]'
 *
 * 
 * Given an unsorted array of integers, find the number of longest increasing
 * subsequence.
 * 
 * 
 * Example 1:
 * 
 * Input: [1,3,5,4,7]
 * Output: 2
 * Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1,
 * 3, 5, 7].
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: [2,2,2,2,2]
 * Output: 5
 * Explanation: The length of longest continuous increasing subsequence is 1,
 * and there are 5 subsequences' length is 1, so output 5.
 * 
 * 
 * 
 * Note:
 * Length of the given array will be not exceed 2000 and the answer is
 * guaranteed to be fit in 32-bit signed int.
 * 
 */
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++)
                if(nums[j] < nums[i] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    cnt[i] = cnt[j];
                }else if(nums[j] < nums[i] && dp[j]+1 == dp[i])
                    cnt[i] += cnt[j];
        }
        int ans = 0;
        int pos = 0;
        // for(auto e: dp)
        //     cout<<e<<" ";
        // cout<<"\n";
        // for(auto e: cnt)
        //     cout<<e<<" ";
        
        for(int i=0; i<n; i++)
            if(pos < dp[i])
                pos = dp[i], ans = cnt[i];
            else if(pos == dp[i])
                ans += cnt[i];
        return ans;
    }
};
