/*
 * @lc app=leetcode id=216 lang=cpp
 *
 * [216] Combination Sum III
 *
 * https://leetcode.com/problems/combination-sum-iii/description/
 *
 * algorithms
 * Medium (50.44%)
 * Total Accepted:    122.5K
 * Total Submissions: 237.3K
 * Testcase Example:  '3\n7'
 *
 * 
 * Find all possible combinations of k numbers that add up to a number n, given
 * that only numbers from 1 to 9 can be used and each combination should be a
 * unique set of numbers.
 * 
 * Note:
 * 
 * 
 * All numbers will be positive integers.
 * The solution set must not contain duplicate combinations.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: k = 3, n = 7
 * Output: [[1,2,4]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: k = 3, n = 9
 * Output: [[1,2,6], [1,3,5], [2,3,4]]
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void callme(int start, int k, int n, vector<int>& local, vector<vector<int>>& res){
        if(n == 0 && k==0){
            res.push_back(local);
            return;
        }
        if(n < 0 || k < 0)
            return;
        for(int i=start; i<=9; i++){
            local.push_back(i);
            callme(i+1, k-1, n-i, local, res);
            local.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> local;
        callme(1, k, n, local, res);
        return res;
    }
};
