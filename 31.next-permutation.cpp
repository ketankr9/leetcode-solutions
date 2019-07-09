/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (30.68%)
 * Likes:    1883
 * Dislikes: 593
 * Total Accepted:    248.2K
 * Total Submissions: 808.9K
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n < 2)
            return;
        int i = n-1;
        while(i-1>=0 && nums[i-1] >= nums[i]){
            i--;
        }
        if(i == 0){
            sort(nums.begin(), nums.end());
            return ;
        }
        int k = n-1;
        while(k>i-1 && nums[i-1]>=nums[k])
            k--;
        // cout<<i-1<<" "<<k;
        int temp = nums[k];
        nums[k] = nums[i-1];
        nums[i-1] = temp;
        sort(nums.begin()+i, nums.end());
    }
};

