/*
 * @lc app=leetcode id=376 lang=cpp
 *
 * [376] Wiggle Subsequence
 *
 * https://leetcode.com/problems/wiggle-subsequence/description/
 *
 * algorithms
 * Medium (36.88%)
 * Total Accepted:    47.9K
 * Total Submissions: 127.9K
 * Testcase Example:  '[1,7,4,9,2,5]'
 *
 * A sequence of numbers is called a wiggle sequence if the differences between
 * successive numbers strictly alternate between positive and negative. The
 * first difference (if one exists) may be either positive or negative. A
 * sequence with fewer than two elements is trivially a wiggle sequence.
 * 
 * For example, [1,7,4,9,2,5] is a wiggle sequence because the differences
 * (6,-3,5,-7,3) are alternately positive and negative. In contrast,
 * [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its
 * first two differences are positive and the second because its last
 * difference is zero.
 * 
 * Given a sequence of integers, return the length of the longest subsequence
 * that is a wiggle sequence. A subsequence is obtained by deleting some number
 * of elements (eventually, also zero) from the original sequence, leaving the
 * remaining elements in their original order.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,7,4,9,2,5]
 * Output: 6
 * Explanation: The entire sequence is a wiggle sequence.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,17,5,10,13,15,10,5,16,8]
 * Output: 7
 * Explanation: There are several subsequences that achieve this length. One is
 * [1,17,10,13,10,16,8].
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [1,2,3,4,5,6,7,8,9]
 * Output: 2
 * 
 * Follow up:
 * Can you do it in O(n) time?
 * 
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, unordered_map<bool, int>> mm;
    int callme(vector<int>& nums, int k, bool big){
        if(k<0)
            return 0;
        if(k == 0)
            return 1;
        if(mm.find(k)!=mm.end() && mm[k].find(big)!=mm[k].end())
            return mm[k][big];

        int maxx = 1;
        for(int i=0; i<k; i++){
            if(big && nums[i] < nums[k])
                maxx = max(maxx, 1+callme(nums, i, false));
            else if(!big && nums[i] > nums[k])
                maxx = max(maxx, 1+callme(nums, i, true));
        }
        mm[k][big] = maxx;
        return maxx;
    }
    int wiggleMaxLength(vector<int>& nums) {
        mm.clear();
        return max(callme(nums, (int)nums.size()-1, true), callme(nums, (int)nums.size()-1, false));
    }
};
