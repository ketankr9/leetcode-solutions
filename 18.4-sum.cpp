/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 *
 * https://leetcode.com/problems/4sum/description/
 *
 * algorithms
 * Medium (30.89%)
 * Likes:    1135
 * Dislikes: 224
 * Total Accepted:    243.8K
 * Total Submissions: 789.2K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * Given an array nums of n integers and an integer target, are there elements
 * a, b, c, and d in nums such that a + b + c + d = target? Find all unique
 * quadruplets in the array which gives the sum of target.
 * 
 * Note:
 * 
 * The solution set must not contain duplicate quadruplets.
 * 
 * Example:
 * 
 * 
 * Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	// vector<int> nums;
	// bool comp(const pair<int, int>& p1, const pair<int, int>& p2){ 
	// 	if(nums[p1.first]+nums[p1.second] == nums[p2.first]+nums[p2.second])
	// 		if(p1.first == p2.first)
	// 			return p1.second < p2.second;
	// 		else
	// 			return p1.first < p2.first;
	// 	return nums[p1.first]+nums[p1.second] < nums[p2.first]+nums[p2.second]; 
	// }
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    	// nums = nums_;

        // vector<pair<int, int>> vec;
        int n = nums.size();
        
        // for(int i=0; i<n; i++)
        // 	for(int j=i+1; j<n; j++)
        // 		vec.push_back({i, j});
        
        // sort(vec.begin(), vec.end(), comp);

        // int i = 0, j = vec.size(); j--;
        // while(i<j){
        // 	int sum = nums[vec[i].first]+nums[vec[i].second]+nums[vec[j].first]+nums[vec[j].second];
        // 	if(sum < target){
        // 		i++;
        // 	}else if(sum > target){
        // 		j--;
        // 	}else{

        // 	}
        // }
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        unordered_map<int, int> mm;
        
        for(int i=0; i<n; i++)
        	mm[nums[i]] = max(mm[nums[i]], i);

        int i = 0;
        while(i<n){
        	int j = i+1;
        	while(j<n){
        		int k = j+1;
        		while(k<n){
        			int sum = target-nums[i]-nums[j]-nums[k];
        			if(mm.find(sum)!=mm.end() && mm[sum] > k){
	        				vector<int> tmp = {nums[i], nums[j], nums[k], sum};
	        				ans.push_back(tmp);
	        		}
	        		int tmp = nums[k];
	        		while(k<n && tmp == nums[k])
        			k++;
        		}
        		int tmp = nums[j];
        		while(j<n && nums[j] == tmp)
        		j++;
        	}
        	int tmp = nums[i];
        	while(i<n && nums[i] == tmp)
        		i++;
        }
        return ans;

    }
};

