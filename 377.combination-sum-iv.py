#
# @lc app=leetcode id=377 lang=python
#
# [377] Combination Sum IV
#
# https://leetcode.com/problems/combination-sum-iv/description/
#
# algorithms
# Medium (43.72%)
# Total Accepted:    85.5K
# Total Submissions: 195.5K
# Testcase Example:  '[1,2,3]\n4'
#
# Given an integer array with all positive numbers and no duplicates, find the
# number of possible combinations that add up to a positive integer target.
# 
# Example:
# 
# 
# nums = [1, 2, 3]
# target = 4
# 
# The possible combination ways are:
# (1, 1, 1, 1)
# (1, 1, 2)
# (1, 2, 1)
# (1, 3)
# (2, 1, 1)
# (2, 2)
# (3, 1)
# 
# Note that different sequences are counted as different combinations.
# 
# Therefore the output is 7.
# 
# 
# 
# 
# Follow up:
# What if negative numbers are allowed in the given array?
# How does it change the problem?
# What limitation we need to add to the question to allow negative numbers?
# 
# Credits:
# Special thanks to @pbrother for adding this problem and creating all test
# cases.
# 
#
class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        d = [0]*(target+1)
        d[0] = 1
        for i in range(1, target+1):
            for e in nums:
                if i-e>=0:
                    d[i] += d[i-e]
        return d[target]
        
