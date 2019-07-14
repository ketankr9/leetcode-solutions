#
# @lc app=leetcode id=241 lang=python
#
# [241] Different Ways to Add Parentheses
#
# https://leetcode.com/problems/different-ways-to-add-parentheses/description/
#
# algorithms
# Medium (50.48%)
# Total Accepted:    76.2K
# Total Submissions: 150.9K
# Testcase Example:  '"2-1-1"'
#
# Given a string of numbers and operators, return all possible results from
# computing all the different possible ways to group numbers and operators. The
# valid operators are +, - and *.
# 
# Example 1:
# 
# 
# Input: "2-1-1"
# Output: [0, 2]
# Explanation: 
# ((2-1)-1) = 0 
# (2-(1-1)) = 2
# 
# Example 2:
# 
# 
# Input: "2*3-4*5"
# Output: [-34, -14, -10, -10, 10]
# Explanation: 
# (2*(3-(4*5))) = -34 
# ((2*3)-(4*5)) = -14 
# ((2*(3-4))*5) = -10 
# (2*((3-4)*5)) = -10 
# (((2*3)-4)*5) = 10
# 
#
class Solution(object):
    def diffWaysToCompute(self, x):
        """
        :type input: str
        :rtype: List[int]
        """
        ans = []
        def callme(arr):
            if len(arr) == 1:
                return [int(arr[0])]
            elif len(arr) == 0:
                return []
            
            tmp = []
            for i in range(1, len(arr), 2):
                if arr[i] == '*':
                    for x in callme(arr[:i]):
                        for y in callme(arr[i+1:]):
                            tmp.append(x*y)
                elif arr[i] == '-':
                    for x in callme(arr[:i]):
                        for y in callme(arr[i+1:]):
                            tmp.append(x-y)
                elif arr[i] == '+':
                    for x in callme(arr[:i]):
                        for y in callme(arr[i+1:]):
                            tmp.append(x+y)
            return tmp

        x = " - ".join(x.split('-'))
        x = " * ".join(x.split('*'))
        x = " + ".join(x.split('+'))
        x = x.split()
        
        return callme(x)
        
