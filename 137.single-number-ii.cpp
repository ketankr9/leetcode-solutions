/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (46.35%)
 * Likes:    861
 * Dislikes: 261
 * Total Accepted:    171.1K
 * Total Submissions: 369.1K
 * Testcase Example:  '[2,2,3,2]'
 *
 * Given a non-empty array of integers, every element appears three times
 * except for one, which appears exactly once. Find that single one.
 * 
 * Note:
 * 
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 * Example 1:
 * 
 * 
 * Input: [2,2,3,2]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [0,1,0,1,0,1,99]
 * Output: 99
 * 
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int bits = 32;
        vector<int> vec(bits, 0);
        
        for(int i=0; i<(int)nums.size(); i++){
            for(int j=0; j<bits; j++)
                vec[j] += (nums[i]&(1<<j))!=0;
        }
        int ans = 0;
        for(int i=0; i<bits; i++){
            vec[i]=vec[i]%3;
            if(vec[i]!=0)
                ans |= (1<<i);
        }
        return ans;

    }
};

