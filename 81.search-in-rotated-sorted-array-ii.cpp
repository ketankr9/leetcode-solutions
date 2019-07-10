/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 *
 * https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Medium (32.64%)
 * Total Accepted:    176K
 * Total Submissions: 538.9K
 * Testcase Example:  '[2,5,6,0,0,1,2]\n0'
 *
 * Suppose an array sorted in ascending order is rotated at some pivot unknown
 * to you beforehand.
 * 
 * (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
 * 
 * You are given a target value to search. If found in the array return true,
 * otherwise return false.
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 0
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [2,5,6,0,0,1,2], target = 3
 * Output: false
 * 
 * Follow up:
 * 
 * 
 * This is a follow up problem to Search in Rotated Sorted Array, where nums
 * may contain duplicates.
 * Would this affect the run-time complexity? How and why?
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findme(int low, int high, const vector<int>& nums, const int &target){
        bool flag = false;
        if(low>high)
            return false;
        // while(low<=high){
            int mid = (low+high)/2;
            if(target == nums[mid])
                return true;
            if(nums[low]<=nums[mid]){ //left sorted
                if(nums[low]<=target && target < nums[mid])
                    flag |= findme(low, mid-1, nums, target);//high = mid-1;
                else
                    flag |= findme(mid+1, high, nums, target);//low = mid+1;
            }
            if(nums[mid]<=nums[high]){ // right sorted
                if(nums[mid]<target && target<=nums[high])
                    flag |= findme(mid+1, high, nums, target);//low = mid+1;
                else
                    flag |= findme(low, mid-1, nums, target);//high = mid-1;
            }
        // }
        return flag;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n-1;
        return findme(low, high, nums, target);
        // while(low<=high){
        //     int mid = (low+high)/2;
        //     if(target == nums[mid])
        //         return true;
        //     if(nums[low]<=nums[mid]){ //left sorted
        //         if(nums[low]<=target && target < nums[mid])
        //             high = mid-1;
        //         else
        //             low = mid+1;
        //     }else{ // right sorted
        //         if(nums[mid]<target && target<=nums[high])
        //             low = mid+1;
        //         else
        //             high = mid-1;
        //     }
        // }
        // return false;
    }
};
