/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * algorithms
 * Medium (42.40%)
 * Likes:    2130
 * Dislikes: 56
 * Total Accepted:    114.7K
 * Total Submissions: 270.4K
 * Testcase Example:  '[1,1,1]\n2'
 *
 * Given an array of integers and an integer k, you need to find the total
 * number of continuous subarrays whose sum equals to k.
 * 
 * Example 1:
 * 
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * 
 * 
 * 
 * Note:
 * 
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the
 * integer k is [-1e7, 1e7].
 * 
 * 
 * 
 */
class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        vector<int> dp(n+1, 0);

        for(int i=0; i<n; i++){
            dp[i+1] = dp[i] + nums[i];
            // ans += (nums[i] == target;   
        }
        
        
        for(int k=0; k<=n; k++){
            for(int i=k+1; i<=n; i++){
                ans += (dp[i]-dp[k]) == target;
            }
        }
        
        return ans;
    }
};

