/*
 * @lc app=leetcode id=628 lang=cpp
 *
 * [628] Maximum Product of Three Numbers
 *
 * https://leetcode.com/problems/maximum-product-of-three-numbers/description/
 *
 * algorithms
 * Easy (45.54%)
 * Total Accepted:    66.1K
 * Total Submissions: 144.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given an integer array, find three numbers whose product is maximum and
 * output the maximum product.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,3]
 * Output: 6
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,3,4]
 * Output: 24
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * The length of the given array will be in range [3,104] and all elements are
 * in the range [-1000, 1000].
 * Multiplication of any three numbers in the input won't exceed the range of
 * 32-bit signed integer.
 * 
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1=INT_MIN, max2=INT_MIN, max3=INT_MIN;
        int min1=INT_MAX, min2=INT_MAX;
        // min1 < min2 < max3 < max2 < max1
        for(auto x: nums){
            if(x > max1){
                max3 = max2;
                max2 = max1;
                max1 = x;
            }else if(x > max2){
                max3 = max2;
                max2 = x;
            }else if(x > max3){
                max3 = x;
            }
            if(x < min1){
                min2 = min1;
                min1 = x;
            }else if(x < min2){
                min2 = x;
            }
        }
        return max(max3*max2*max1, max1*min1*min2);
    }
};
