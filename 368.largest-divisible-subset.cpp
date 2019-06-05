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
    // vector<int> ans;
    // vector<int> vec;
    unordered_map<int, vector<int>> mm;
    vector<int> callme(vector<int>& nums, int i){
        
        if(i >= (int)nums.size())
            return vector<int>();

        if(mm.find(i)!=mm.end()){
            return mm[i];
        }
        
        int prev = nums[i], k = i;
        i++;
        vector<int> ret;
        
        while(i<=(int)nums.size()){
            while(i<(int)nums.size() && nums[i]%prev!=0)
                i++;
            vector<int> tmp = callme(nums, i);
            if(tmp.size() > ret.size())
                ret = tmp;
            i++;
        }
        ret.push_back(prev);
        mm[k] = ret;
        return ret;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // ans.clear();
        // vec.clear();
        mm.clear();
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i=0; i<(int)nums.size(); i++){
            vector<int> tmp = callme(nums, i);
            if(tmp.size() > ans.size())
                ans = tmp;
            }
        return ans;
    }
};
