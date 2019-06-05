/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 *
 * https://leetcode.com/problems/largest-divisible-subset/description/
 *
 * algorithms
 * Medium (34.47%)
 * Total Accepted:    45.1K
 * Total Submissions: 130.2K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct positive integers, find the largest subset such that
 * every pair (Si, Sj) of elements in this subset satisfies:
 * 
 * Si % Sj = 0 or Sj % Si = 0.
 * 
 * If there are multiple solutions, return any subset is fine.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: [1,2,3]
 * Output: [1,2] (of course, [1,3] will also be ok)
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,4,8]
 * Output: [1,2,4,8]
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n == 0)
            return vector<int>();
        if(n == 1)
            return nums;
        vector<int> vec(n, 1);
        vector<int> prev(n, -1);
        int start = -1, gmax = 0;
        for(int i=1; i<n; i++){
            int maxx = 0, ind = -1;
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0 && vec[j] > maxx){
                    maxx = vec[j];
                    ind = j;
                }
                vec[i] = maxx+1;
                if(vec[i] > gmax){
                    gmax = vec[i];
                    start = i; 
                }
            }

            if(maxx != 0)
                prev[i] = ind;
        }
        vector<int> ans;
        while(start!=-1){
            ans.push_back(nums[start]);
            start = prev[start];
        }
        return ans;
    }
};
