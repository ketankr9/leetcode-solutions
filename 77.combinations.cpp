/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (48.34%)
 * Likes:    814
 * Dislikes: 48
 * Total Accepted:    210.1K
 * Total Submissions: 434.6K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> visited;
    vector<vector<int>> ans;
    vector<int> local;
    void callme(int pos, int k, int n){
        if((int)local.size() == k){
            ans.push_back(local);
            return;
        }
        if(pos == n)
            return;
        callme(pos+1, k, n);
        local.push_back(pos+1);
        callme(pos+1, k, n);
        local.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        visited = vector<bool>(n, false);
        local.clear();
        ans.clear();
        callme(0, k, n);
        return ans;
    }
};

