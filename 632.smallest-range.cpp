/*
 * @lc app=leetcode id=632 lang=cpp
 *
 * [632] Smallest Range
 *
 * https://leetcode.com/problems/smallest-range/description/
 *
 * algorithms
 * Hard (48.38%)
 * Total Accepted:    25.4K
 * Total Submissions: 52.4K
 * Testcase Example:  '[[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]'
 *
 * You have k lists of sorted integers in ascending order. Find the smallest
 * range that includes at least one number from each of the k lists. 
 * 
 * We define the range [a,b] is smaller than range [c,d] if b-a < d-c or a < c
 * if b-a == d-c.
 * 
 * Example 1:
 * 
 * Input:[[4,10,15,24,26], [0,9,12,20], [5,18,22,30]]
 * Output: [20,24]
 * Explanation: 
 * List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
 * List 2: [0, 9, 12, 20], 20 is in range [20,24].
 * List 3: [5, 18, 22, 30], 22 is in range [20,24].
 * 
 * 
 * 
 * 
 * Note:
 * 
 * The given list may contain duplicates, so ascending order means >= here.
 * 1 k 
 * ⁠-105 value of elements 5.
 * For Java users, please note that the input type has been changed to
 * List<List<Integer>>. And after you reset the code template, you'll see this
 * point.
 * 
 * 
 * 
 */
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> ans(2, 0);
        if(n == 0)  return ans;
        int diff = INT_MAX;
        int k = nums[0].size();

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> nexti(n, 0);

        int end = INT_MIN;
        for(int i=0; i<n; i++){
            pq.push(make_pair(nums[i][nexti[i]], i));
            end = max(end, nums[i][nexti[i]]);
            nexti[i]++;
        }

        while(!pq.empty()){
            pair<int, int> top = pq.top(); pq.pop();
            // cout<<top.first<<":"<<top.second<<" ";
            if(diff > end - top.first){
                diff = end - top.first;
                ans = {top.first, end};
            }
            if(nexti[top.second] == nums[top.second].size())
                break;
            end = max(end, nums[top.second][nexti[top.second]]);
            pq.push(make_pair(nums[top.second][nexti[top.second]], top.second));
            nexti[top.second]++;
        }

        return ans;

    }
};
