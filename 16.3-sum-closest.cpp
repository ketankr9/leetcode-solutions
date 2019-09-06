/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 *
 * https://leetcode.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (45.79%)
 * Likes:    1180
 * Dislikes: 86
 * Total Accepted:    359K
 * Total Submissions: 784K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * Given an array nums of n integers and an integer target, find three integers
 * in nums such that the sum is closest to target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.
 * 
 * Example:
 * 
 * 
 * Given array nums = [-1, 2, 1, -4], and target = 1.
 * 
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// #define for(i, n) for(int i=0; i<n; i++)
    int threeSumClosest(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
    	int n = nums.size();
    	int diff = INT_MAX;
    	int ans;

    	for(int i=0; i<n; i++)
    		for(int j=i+1; j<n; j++){
    			auto it = upper_bound(nums.begin()+j+1, nums.end(), target-nums[i]-nums[j]);
    			if(it != nums.end() && diff > abs(target-nums[i]-nums[j]-*it)){
    				diff = abs(target-nums[i]-nums[j]-*it);
    				ans = nums[i]+nums[j]+*it;
    			}
    			if(it-nums.begin()-1!=j && diff > abs(target-nums[i]-nums[j]-*(it-1))){
    				diff = abs(target-nums[i]-nums[j]-*(it-1));
    				ans = nums[i]+nums[j]+*(it-1);
    			}
    		}

    	return ans;
    }
};

