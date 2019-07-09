/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (41.07%)
 * Total Accepted:    252.7K
 * Total Submissions: 615.4K
 * Testcase Example:  '[1,1,2]'
 *
 * <p>Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.</p>
 * 
 * <p><strong>Example:</strong></p>
 * 
 * <pre>
 * <strong>Input:</strong> [1,1,2]
 * <strong>Output:</strong>
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * </pre>
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> local;
    vector<bool> visited;
    void callme(int k, const vector<int> &nums){
        int n = nums.size();
        if(k == nums.size()){
            ans.push_back(local);
            return;
        }
        int i=0;
        while(i<n){
            if(visited[i]){
                i++;
                continue;
            }
            visited[i] = true;
            local.push_back(nums[i]);
            callme(k+1, nums);
            local.pop_back();
            visited[i] = false;
            while(i+1<n && nums[i]==nums[i+1])
                i++;
            i++;
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        ans.clear();
        local.clear();
        visited = vector<bool>(nums.size(), false);
        callme(0, nums);
        return ans;
    }   
};
