/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (39.86%)
 * Total Accepted:    87.5K
 * Total Submissions: 215.1K
 * Testcase Example:  '[1,5,11,5]'
 *
 * <p>Given a <b>non-empty</b> array containing <b>only positive integers</b>,
 * find if the array can be partitioned into two subsets such that the sum of
 * elements in both subsets is equal.</p>
 * 
 * <p><b>Note:</b></p>
 * 
 * <ol>
 * <li>Each of the array element will not exceed 100.</li>
 * <li>The array size will not exceed 200.</li>
 * </ol>
 * 
 * <p>&nbsp;</p>
 * 
 * <p><b>Example 1:</b></p>
 * 
 * <pre>
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * </pre>
 * 
 * <p>&nbsp;</p>
 * 
 * <p><b>Example 2:</b></p>
 * 
 * <pre>
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * </pre>
 * 
 * <p>&nbsp;</p>
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int summ = 0;
        int n = nums.size();
        if(n==1)    return false;
        for(auto e: nums)
            summ+=e;
        if(summ%2)  return false;
        vector<bool> d((summ/2)+1, false);
        d[0] = true;
        for(auto e: nums){
            for(int i=summ/2; i>=0; i--){
                if(i-e>=0 && d[i-e])
                    d[i] = true;
            }
        }
        return d[summ/2];
    }
};
