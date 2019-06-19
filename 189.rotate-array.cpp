/*
 * @lc app=leetcode id=189 lang=cpp
 *
 * [189] Rotate Array
 *
 * https://leetcode.com/problems/rotate-array/description/
 *
 * algorithms
 * Easy (30.31%)
 * Total Accepted:    305.7K
 * Total Submissions: 1M
 * Testcase Example:  '[1,2,3,4,5,6,7]\n3'
 *
 * Given an array, rotate the array to the right by k steps, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3,4,5,6,7] and k = 3
 * Output: [5,6,7,1,2,3,4]
 * Explanation:
 * rotate 1 steps to the right: [7,1,2,3,4,5,6]
 * rotate 2 steps to the right: [6,7,1,2,3,4,5]
 * rotate 3 steps to the right: [5,6,7,1,2,3,4]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [-1,-100,3,99] and k = 2
 * Output: [3,99,-1,-100]
 * Explanation: 
 * rotate 1 steps to the right: [99,-1,-100,3]
 * rotate 2 steps to the right: [3,99,-1,-100]
 * 
 * 
 * Note:
 * 
 * 
 * Try to come up as many solutions as you can, there are at least 3 different
 * ways to solve this problem.
 * Could you do it in-place with O(1) extra space?
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // int GCD(int a, int b){
    //     if(a == 0 || b == 0)
    //         return a+b;
    //     if(a>b)
    //         swap(a, b);
    //     return GCD(b%a, a);
    // }
    void reverse(vector<int>& nums, int start, int end){
        while(start<end){
            swap(nums[start], nums[end-1]);
            start++;
            end--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k%n;
        // k = n-k;
        // int gcd = GCD(n, k);
        // for(int start=0; start<gcd; start++){
        //     int cur = start;
        //     int tmp = nums[start];
        //     while((cur+k)%n!=start){
        //         nums[cur] = nums[(cur+k)%n];
        //         cur = (cur+k)%n;
        //     }
        //     nums[cur] = tmp;
        // }
        reverse(nums, 0, n-k);
        reverse(nums, n-k, n);
        reverse(nums, 0, nums.size());
    }
};
