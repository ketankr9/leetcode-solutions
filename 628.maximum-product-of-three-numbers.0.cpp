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
        int max_prod = nums[0]*nums[1]*nums[2];
        if(nums.size() == 3){
            return max_prod;
        }
        vector<int> max_vec;
        vector<int> min_vec;
        vector<int> max_vec2;

        for(auto x: nums){
            if(x >= 0){
                if(max_vec.size() < 3)
                    max_vec.push_back(x);
                else{
                    if(max_vec[0] < x && max_vec[1] >= max_vec[0] && max_vec[2] >= max_vec[0])
                        max_vec[0] = x;
                    else if(max_vec[1] < x && max_vec[2] >= max_vec[1] && max_vec[0] >= max_vec[1])
                        max_vec[1] = x;
                    else if(max_vec[2] < x && max_vec[0] >= max_vec[2] && max_vec[1] >= max_vec[2])
                        max_vec[2] = x;
                }
            }else if(x < 0){
                if(min_vec.size() < 3)
                    min_vec.push_back(x);
                else{
                    if(min_vec[0] > x && min_vec[1] <= min_vec[0] && min_vec[2] <= min_vec[0])
                        min_vec[0] = x;
                    else if(min_vec[1] > x && min_vec[2] <= min_vec[1] && min_vec[0] <= min_vec[1])
                        min_vec[1] = x;
                    else if(min_vec[2] > x && min_vec[0] <= min_vec[2] && min_vec[1] <= min_vec[2])
                        min_vec[2] = x;
                }
                if(max_vec2.size() < 3)
                    max_vec2.push_back(x);
                else{
                    if(max_vec2[0] < x && max_vec2[1] >= max_vec2[0] && max_vec2[2] >= max_vec2[0])
                        max_vec2[0] = x;
                    else if(max_vec2[1] < x && max_vec2[2] >= max_vec2[1] && max_vec2[0] >= max_vec2[1])
                        max_vec2[1] = x;
                    else if(max_vec2[2] < x && max_vec2[0] >= max_vec2[2] && max_vec2[1] >= max_vec2[2])
                        max_vec2[2] = x;
                }
            }
        }
        for(auto e: min_vec)
            cout<<e<<" ";
        cout<<"\n";
        for(auto e: max_vec)
            cout<<e<<" ";
        cout<<"\n";
        for(auto e: max_vec2)
            cout<<e<<" ";
        // all numbers are -ve $ max_vec.size() == 0
        if((int)max_vec.size() == 0)
            return max_vec2[0]*max_vec2[1]*max_vec2[2];
        //at least one positive
            // min_vec.size() >=2
            if(min_vec.size() == 2){
                int maxx = min_vec[0], prod = 1;
                prod = min_vec[0]*min_vec[1];
                maxx = max_vec[0];
                for(auto e: max_vec) maxx = max(maxx, e);
                return prod*maxx;
            }else if(min_vec.size() > 2){
                int maxx = min_vec[0], prod = 1;
                for(auto e: min_vec) maxx = max(maxx, e);
                prod = min_vec[0]*min_vec[1]*min_vec[2];
                prod /= maxx;
                maxx = max_vec[0];
                for(auto e: max_vec) maxx = max(maxx, e);
                max_prod = prod*maxx;
            }
            // min_vec.size() < 2
            if(max_vec.size() >= 3)
            return max(max_vec[0]*max_vec[1]*max_vec[2], max_prod);
            return max_prod;

    }
};
